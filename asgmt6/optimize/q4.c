// All Lengths are in units of sigma(diameter of the particle)
// All Energies are in units of KbT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<omp.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

static inline double PBC(double position,double box_size)
{
        // Take modulo of position with box size
        double modulo_position = fmod(position, box_size);
        
        double final_coordinate = modulo_position;
        // If position is negative after modulo, add the size of the box
        if(modulo_position < 0){
                final_coordinate = modulo_position + box_size;
        }
        return final_coordinate;
}

static inline double int_pow(double x,int a)
{
        // Calculates x^a
        for(int i=1; i<a; i++){
                x = x * x;
        }
        return x;
}

static inline double calc_dist(double box_size, double x1_pos, double x2_pos, double y1_pos,
                double y2_pos, double z1_pos, double z2_pos)
{
        // Naive component-wise distance ignoring PBC
        double x_dist = fabs(x1_pos - x2_pos);
        double y_dist = fabs(y1_pos - y2_pos);
        double z_dist = fabs(z1_pos - z2_pos);

        // If naive distance is greater than half the box size, apply PBC
        double updated_x_dist = box_size - x_dist;
        if(x_dist > updated_x_dist){
                x_dist = updated_x_dist;
        }
        double updated_y_dist = box_size - y_dist;
        if(y_dist > updated_y_dist){
                y_dist = updated_y_dist;
        }
        double updated_z_dist = box_size - z_dist;
        if(z_dist > updated_z_dist){
                z_dist = updated_z_dist;
        }
        
        // Calculate distance between the particles with the component-wise dist
        double dist = sqrt((x_dist * x_dist) + (y_dist * y_dist) + (z_dist * z_dist));

        return dist;
}

void initialize_positions(int no_of_part, double box_size, double x_position[], 
                double y_position[], double z_position[])
{
        for(int i=0; i < no_of_part; i++){
                // Randomly initialize positions
                x_position[i] = frand() * box_size;
                y_position[i] = frand() * box_size;
                z_position[i] = frand() * box_size;
                
                for(int j=0; j < i; j++){
                        // If the particles overlap with others, initialize again
                        double dist;
                        dist = calc_dist(box_size, x_position[i], x_position[j], y_position[i],
                                        y_position[j], z_position[i], z_position[j]);
                        if(dist < 1){
                                i = i-1;
                                break;
                        }
                }
        }
}

void initialize_velocies(int no_of_part, double KbT, double mass, double x_velocity[], 
                double y_velocity[], double z_velocity[])
{
        double tot_x_vel = 0;
        double tot_y_vel = 0;
        double tot_z_vel = 0;

        double A = sqrt(12*KbT/mass);
        // Randomly initialize velocities
        for(int i=0; i < no_of_part; i++){
                x_velocity[i] = A * (frand() - 0.5);
                y_velocity[i] = A * (frand() - 0.5);
                z_velocity[i] = A * (frand() - 0.5);

                tot_x_vel += x_velocity[i];
                tot_y_vel += y_velocity[i];
                tot_z_vel += z_velocity[i];
        }
        double avg_x_vel = tot_x_vel/no_of_part;
        double avg_y_vel = tot_y_vel/no_of_part;
        double avg_z_vel = tot_z_vel/no_of_part;

        // Make sure that average velocity is 0
        for(int i=0; i < no_of_part; i++){
                x_velocity[i] -= avg_x_vel;
                y_velocity[i] -= avg_y_vel;
                z_velocity[i] -= avg_z_vel;
        }
}

void force_calc(double sigma, double epsilon, double x_position[], double y_position[],
                double z_position[], double cutoff_distance, double force_arr_x[],
                double force_arr_y[], double force_arr_z[], int no_of_part, double box_size,
                int neigh_track_list[], int neigh_list[])
{
        // Calculate force at cutoff radius once
        double Frc = (4 * epsilon) * (((12 * int_pow(sigma, 12))/(int_pow(cutoff_distance, 13)))
                        - ((6 * int_pow(sigma, 6))/(int_pow(cutoff_distance, 7))));
        
        double force_x[no_of_part];
        double force_y[no_of_part];
        double force_z[no_of_part];

        for(int i=0; i < no_of_part; i++){
                force_x[i] = 0;
                force_y[i] = 0;
                force_z[i] = 0;
        }

        #pragma omp parallel for reduction(+:force_x[:no_of_part], force_y[:no_of_part], force_z[:no_of_part]) schedule(dynamic, 16)
        for(int i=0; i < no_of_part; i++){
                int start_index = neigh_track_list[i];
                int end_index = neigh_track_list[i+1];

                for(int k=start_index; k < end_index; k++){
                        int j = neigh_list[k];

                        if(j>i){
                                double distance = calc_dist(box_size, x_position[i], x_position[j], y_position[i],
                                                y_position[j], z_position[i], z_position[j]);
                                if(distance < cutoff_distance){
                                        double force_mag = ((4 * epsilon) * (((12 * int_pow(sigma, 12))
                                                                              /(int_pow(distance, 13)))
                                                - ((6 * int_pow(sigma, 6))/(int_pow(distance, 7))))) - Frc;
                                        double x_diff = x_position[j]-x_position[i];
                                        double y_diff = y_position[j]-y_position[i];
                                        double z_diff = z_position[j]-z_position[i];

                                        double half_box_size = box_size/2;

                                        if(fabs(x_diff) > half_box_size){
                                                if(x_diff > 0){
                                                        x_diff = x_diff - box_size;
                                                } else{
                                                        x_diff = box_size + x_diff;
                                                }
                                        }
                                        if(fabs(y_diff) > half_box_size){
                                                if(y_diff > 0){
                                                        y_diff = (y_diff - box_size);
                                                } else{
                                                        y_diff = box_size + y_diff;
                                                }
                                        }
                                        if(fabs(z_diff) > half_box_size){
                                                if(z_diff > 0){
                                                        z_diff = (z_diff - box_size);
                                                } else{
                                                        z_diff = box_size + z_diff;
                                                }
                                        }
                                        double fx_ij = (-force_mag * x_diff)/distance;
                                        double fy_ij = (-force_mag * y_diff)/distance;
                                        double fz_ij = (-force_mag * z_diff)/distance;
                                        
                                        force_x[i] += fx_ij;
                                        force_x[j] += -fx_ij;
                                        force_y[i] += fy_ij;
                                        force_y[j] += -fy_ij;
                                        force_z[i] += fz_ij;
                                        force_z[j] += -fz_ij;
                                }
                        }
                }
        }
        memcpy(force_arr_x, force_x, sizeof(force_x));
        memcpy(force_arr_y, force_y, sizeof(force_y));
        memcpy(force_arr_z, force_z, sizeof(force_z));
}

void position_update(double x_position[], double y_position[], double z_position[], 
                double x_velocity[], double y_velocity[], double z_velocity[], double f_xt[], double f_yt[], 
                double f_zt[], double dt, double mass, int no_of_part, double box_size)
{
        double coeff = (0.5 * dt * dt)/mass;

        #pragma omp parallel for
        for(int i=0; i < no_of_part; i++){
                // Updating position using velocity verlet algorithm
                x_position[i] += (x_velocity[i] * dt) + (f_xt[i] * coeff);
                y_position[i] += (y_velocity[i] * dt) + (f_yt[i] * coeff);
                z_position[i] += (z_velocity[i] * dt) + (f_zt[i] * coeff);
                
                // Applying PBC
                x_position[i] = PBC(x_position[i], box_size);
                y_position[i] = PBC(y_position[i], box_size);
                z_position[i] = PBC(z_position[i], box_size);
        }
}

void velocity_update(double x_velocity[], double y_velocity[], double z_velocity[], double f_xt[],
                double f_xtp1[], double f_yt[], double f_ytp1[], double f_zt[], 
                double f_ztp1[], double dt, double mass, int no_of_part)
{
        double coeff = (0.5 * dt)/mass;

        #pragma omp parallel for
        for(int i=0; i < no_of_part; i++){
                // Updating velocity using velocity verlet algorithm
                x_velocity[i] += (f_xt[i] + f_xtp1[i]) * coeff;
                y_velocity[i] += (f_yt[i] + f_ytp1[i]) * coeff;
                z_velocity[i] += (f_zt[i] + f_ztp1[i]) * coeff;
        }
}

double calculate_KE(double x_velocity[], double y_velocity[], double z_velocity[], int no_of_part,
                double mass)
{
        double KE_tot = 0;
        double KE_mat[no_of_part];

        #pragma omp parallel for collapse(1)
        for(int i=0; i < no_of_part; i++){
                KE_mat[i] = (0.5 * mass * ((x_velocity[i] * x_velocity[i]) + (y_velocity[i] * y_velocity[i]) 
                                        + (z_velocity[i] * z_velocity[i])));
        }
        for(int i=0; i < no_of_part; i++){
                KE_tot += KE_mat[i];
        }
        return (KE_tot/no_of_part);
}

double calculate_PE(double x_pos[], double y_pos[], double z_pos[], double cutoff_dist,
                int no_of_part, double box_size, double sigma, double epsilon)
{
        double Vrc = ((4 * epsilon) * ((int_pow((sigma/cutoff_dist), 12)) 
                                -(int_pow((sigma/cutoff_dist), 6))));

        double Frc = ((4 * epsilon) * (((12 * int_pow(sigma, 12))/(int_pow(cutoff_dist, 13)))
                        - ((6 * int_pow(sigma, 6))/(int_pow(cutoff_dist, 7)))));
        double shift = -(Vrc + (Frc * cutoff_dist));

        double PE_tot = 0;
        double pair_pot = 0;

        #pragma omp parallel for reduction(+:PE_tot) schedule(dynamic)
        for(int i=0; i < no_of_part; i++){
                for(int j=no_of_part-1; j > i; j--){
                        double dist = calc_dist(box_size, x_pos[i], x_pos[j], y_pos[i],
                                        y_pos[j], z_pos[i], z_pos[j]);
                        if(dist < cutoff_dist){
                                pair_pot = ((4 * epsilon) * ((int_pow((sigma/dist), 12)) 
                                -(int_pow((sigma/dist), 6)))) + (dist * Frc) + shift;
                                PE_tot += pair_pot;
                        }
                }
        }
        return (PE_tot/no_of_part);
}

void thermostat(double x_velocity[], double y_velocity[], double z_velocity[], double KbT, int no_of_part,
                double mass, double system_KE)
{
        double required_KE = 1.5 * KbT;

        // Scale velocities by some factor so that temperatue remains constant.
        double scaling_factor = sqrt(required_KE/system_KE);

        #pragma omp parallel for collapse(1)
        for(int i=0; i < no_of_part; i++){
                x_velocity[i] = x_velocity[i] * scaling_factor;
                y_velocity[i] = y_velocity[i] * scaling_factor;
                z_velocity[i] = z_velocity[i] * scaling_factor;
        }
}

void neighbour_list(double x_pos[], double y_pos[], double z_pos[], double KbT, double dt,
                double cutoff_r, double mass, int n_calc, int no_of_part, double box_size,
                int neigh_list[], int neigh_lst_track[]) 
{
        double v_avg = sqrt((8*KbT)/(M_PI*mass));
        double dr = 2 * 5 * v_avg * (double)n_calc * dt;
        double cut = dr + cutoff_r;

        int k=0;
        for(int i=0; i<no_of_part; i++){
                neigh_lst_track[i] = k;
                for(int j=no_of_part-1; j>i; j--){
                        double distance = calc_dist(box_size, x_pos[i], x_pos[j], y_pos[i], 
                                        y_pos[j], z_pos[i], z_pos[j]);
                        if(distance <= cut){
                                neigh_list[k] = j;
                                k += 1;
                        }
                }
        }
        neigh_lst_track[no_of_part] = k;
}

void pair_correlation(double x_pos[], double y_pos[], double z_pos[], double box_size, int no_of_part,
                double dr, double t_avg[], int n_iter, int n_update)
{
        int n = ceil(box_size/(2*dr));

        double density = no_of_part/(box_size * box_size * box_size);

        double pcf[n];
        for(int i=0; i<n; i++){
                pcf[i] = 0;
        }

        double r_start = 0;
        double r_end = r_start + dr;

        #pragma omp parallel for schedule(dynamic)
        for(int j=0; j < no_of_part - 1; j++){
                for(int k = j + 1; k < no_of_part; k++){
                        double dist = calc_dist(box_size, x_pos[j], x_pos[k], y_pos[j], 
                                                y_pos[k], z_pos[j], z_pos[k]);

                        if(dist<(box_size/2)){
                                int bin = (int)(dist / dr);
                                #pragma omp atomic
                                pcf[bin] += 2.0; 
                        }
                }
        }
        double time_norm = (double)(n_iter-50000)/(double)n_update;

        #pragma omp parallel for
        for(int i = 0; i < n; i++){
                double r = (i + 0.5) * dr; 
                double shell_volume = 4.0 * M_PI * r * r * dr;
                pcf[i] = pcf[i] / (no_of_part * shell_volume * density);
                t_avg[i] += pcf[i]/time_norm;
        }
}

void mb_check(double x_vel[], double y_vel[], double z_vel[], int n_iter, int n_update, 
                double t_avg[], double dv, int num_bin, int no_of_part)
{
        double v[no_of_part];
        double speed[num_bin];

        for(int i=0; i<num_bin; i++){
                speed[i] = 0;
        }

        #pragma omp parallel for
        for(int i=0; i<no_of_part; i++){
                v[i] = sqrt((x_vel[i]*x_vel[i])+(y_vel[i]*y_vel[i])+(z_vel[i]*z_vel[i]));

                int bin = (int)(v[i]/dv);
                if(bin < num_bin){
                        #pragma omp atomic
                        speed[bin] += 1;
                }
        }
        
        double time_norm = (double)(n_iter-50000)/(double)n_update;

        #pragma omp parallel for
        for(int i = 0; i < num_bin; i++){
                        speed[i] = speed[i] / (no_of_part * dv);
                        t_avg[i] += speed[i] / time_norm;
                }
}

int main()
{
        double begin = omp_get_wtime();

        srand(time(NULL));

        int no_of_part = 3600; // Number of particles
        double dt = 0.0025; // Integration time step
        double box_size = 20;
        double epsilon = 1; // Depth of potential minima
        double r_c = 2.5; // Cutoff radius
        double mass = 1;
        double KbT = 1;
        double sigma = 1; // Diameter of the particle

        double *x_position = (double *)malloc(no_of_part * sizeof(double));
        double *y_position = (double *)malloc(no_of_part * sizeof(double));
        double *z_position = (double *)malloc(no_of_part * sizeof(double));
        
        double *x_velocity = (double *)malloc(no_of_part * sizeof(double));
        double *y_velocity = (double *)malloc(no_of_part * sizeof(double));
        double *z_velocity = (double *)malloc(no_of_part * sizeof(double));

        double *x_force = (double *)malloc(no_of_part * sizeof(double));
        double *y_force = (double *)malloc(no_of_part * sizeof(double));
        double *z_force = (double *)malloc(no_of_part * sizeof(double));

        double *x_force_new =  (double *)malloc(no_of_part * sizeof(double));
        double *y_force_new =  (double *)malloc(no_of_part * sizeof(double));
        double *z_force_new =  (double *)malloc(no_of_part * sizeof(double));

        FILE *fPtr;
        fPtr = fopen("KE.dat","w");

        FILE *fPt;
        fPt = fopen("PE.dat","w");

        double KE = 0;
        double PE = 0;

        int *n_list = (int *)malloc(no_of_part * no_of_part * sizeof(int));
        int *n_track_list = (int *)malloc((no_of_part+1) * sizeof(int));

        double dr = 0.05;
        double pair_cf[(int)ceil(box_size/(2*dr))];
        for(int i=0; i<ceil(box_size/(2*dr)); i++){
                pair_cf[i] = 0;
        }

        double dv = 0.05;         
        double max_v = 7.0;
        int num_v_bins = (int)ceil(max_v / dv);

        double speed_mb[num_v_bins];
        for(int i=0; i < num_v_bins; i++){
                speed_mb[i] = 0;
        }

        initialize_positions(no_of_part, box_size, x_position, y_position, z_position);
        initialize_velocies(no_of_part, KbT, mass, x_velocity, y_velocity, z_velocity);

        int n_calc = 20;
        int n_update = 50;

        neighbour_list(x_position, y_position, z_position, KbT, dt, r_c, mass, 
                        n_calc, no_of_part, box_size, n_list, n_track_list);
        force_calc(sigma, epsilon, x_position, y_position, z_position, r_c,
                        x_force, y_force, z_force, no_of_part, box_size, n_track_list, n_list);


        int n_iter = 300;
        for(int i=0; i < n_iter; i++){
                position_update(x_position, y_position, z_position, x_velocity, y_velocity,
                                z_velocity, x_force, y_force, z_force, dt, mass, no_of_part, box_size);
                force_calc(sigma, epsilon, x_position, y_position, z_position, r_c, x_force_new, 
                                y_force_new, z_force_new, no_of_part, box_size, n_track_list, n_list);
                velocity_update(x_velocity, y_velocity, z_velocity, x_force, x_force_new,
                                y_force, y_force_new, z_force, z_force_new, dt, mass, no_of_part);

                // Swap force and force new array before updating force new
                double *tmp_x = x_force; x_force = x_force_new; x_force_new = tmp_x;
                double *tmp_y = y_force; y_force = y_force_new; y_force_new = tmp_y;
                double *tmp_z = z_force; z_force = z_force_new; z_force_new = tmp_z;

                if(i>49999){
                        if(i%n_update == 0){
                                KE = calculate_KE(x_velocity, y_velocity, z_velocity, no_of_part, mass);
                                PE = calculate_PE(x_position, y_position, z_position, r_c, no_of_part, box_size,
                                                sigma, epsilon);
                                pair_correlation(x_position, y_position, z_position, box_size, no_of_part, dr,
                                                pair_cf, n_iter, n_update);
                                mb_check(x_velocity, y_velocity, z_velocity, n_iter, n_update,
                                                speed_mb, dv, num_v_bins, no_of_part);
                                fprintf(fPtr, "%f\n", KE);
                                fprintf(fPt, "%f\n", PE);
                        }
                }

                if(i%n_calc ==0){
                        KE = calculate_KE(x_velocity, y_velocity, z_velocity, no_of_part, mass);
                        thermostat(x_velocity, y_velocity, z_velocity, KbT,
                                        no_of_part, mass, KE);
                        neighbour_list(x_position, y_position, z_position, KbT, dt, r_c, mass, 
                                        n_calc, no_of_part, box_size, n_list, n_track_list);
                }
        }
        free(n_list);
        free(n_track_list);

        FILE *pc;
        pc = fopen("pair_cf.dat","w");

        for(int i=0; i < ceil(box_size/(2*dr)); i++){
                fprintf(pc, "%f\n", pair_cf[i]);
        }

        FILE *mb = fopen("mb.dat","w");
        for(int i=0; i < num_v_bins; i++){
                fprintf(mb, "%f\n", speed_mb[i]);
        }

        fclose(mb);
        fclose(pc);
        fclose(fPtr);
        fclose(fPt);

        free(x_position);
        free(y_position);
        free(z_position);

        free(x_velocity);
        free(y_velocity);
        free(z_velocity);

        free(x_force);
        free(y_force);
        free(z_force);

        free(x_force_new);
        free(y_force_new);
        free(z_force_new);

        double end = omp_get_wtime();
        double time_spent = (end-begin);
        printf("\nSuccessfully finished running in %.8f s.\n",(end-begin));

        return 0;
}

