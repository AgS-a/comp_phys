// All Lengths are in units of sigma(diameter of the particle)
// All Energies are in units of KbT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<omp.h>

#define frand() ((double) rand() / (RAND_MAX+1.0))

double PBC(double position,double box_size)
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

double calc_dist(double box_size, double x1_pos, double x2_pos, double y1_pos,
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
        double dist = sqrt(pow(x_dist, 2) + pow(y_dist, 2) + pow(z_dist, 2));

        return dist;
}

void initialize_positions(int no_of_part, double box_size, double x_pos_array[], 
                double y_pos_array[], double z_pos_array[])
{
        double x_pos[no_of_part];
        double y_pos[no_of_part];
        double z_pos[no_of_part];

        for(int i=0; i < no_of_part; i++){
                // Randomly initialize positions
                x_pos[i] = frand() * box_size;
                y_pos[i] = frand() * box_size;
                z_pos[i] = frand() * box_size;
                
                for(int j=0; j < i; j++){
                        // If the particles overlap with others, initialize again
                        double dist;
                        dist = calc_dist(box_size, x_pos[i], x_pos[j], y_pos[i],
                                        y_pos[j], z_pos[i], z_pos[j]);
                        if(dist < 1.2){
                                i = i-1;
                                break;
                        }
                }
        }
        memcpy(x_pos_array, x_pos, sizeof(x_pos));
        memcpy(y_pos_array, y_pos, sizeof(y_pos));
        memcpy(z_pos_array, z_pos, sizeof(z_pos));
}

void initialize_velocies(int no_of_part, double KbT, double m, double x_vel_array[], 
                double y_vel_array[], double z_vel_array[])
{
        double x_vel[no_of_part];
        double y_vel[no_of_part];
        double z_vel[no_of_part];
        
        double tot_x_vel = 0;
        double tot_y_vel = 0;
        double tot_z_vel = 0;

        double A = sqrt(12*KbT/m);
        // Randomly initialize velocities
        for(int i=0; i < no_of_part; i++){
                x_vel[i] = A * (frand() - 0.5);
                y_vel[i] = A * (frand() - 0.5);
                z_vel[i] = A * (frand() - 0.5);

                tot_x_vel += x_vel[i];
                tot_y_vel += y_vel[i];
                tot_z_vel += z_vel[i];
        }
        double avg_x_vel = tot_x_vel/no_of_part;
        double avg_y_vel = tot_y_vel/no_of_part;
        double avg_z_vel = tot_z_vel/no_of_part;

        // Make sure that average velocity is 0
        for(int i=0; i < no_of_part; i++){
                x_vel[i] = x_vel[i] - avg_x_vel;
                y_vel[i] = y_vel[i] - avg_y_vel;
                z_vel[i] = z_vel[i] - avg_z_vel;
        }

        memcpy(x_vel_array, x_vel, sizeof(x_vel));
        memcpy(y_vel_array, y_vel, sizeof(y_vel));
        memcpy(z_vel_array, z_vel, sizeof(z_vel));
}

// Check this sub-routine again //
void force_calc(double sigma, double epsilon, double x_pos[], double y_pos[],
                double z_pos[], double cutoff_distance, double force_arr_x[],
                double force_arr_y[], double force_arr_z[], int no_of_part, double box_size)
{
        // Calculate force at cutoff radius once
        double Frc = (4 * epsilon) * (((12 * pow(sigma, 12))/(pow(cutoff_distance, 13)))
                        - ((6 * pow(sigma, 6))/(pow(cutoff_distance, 7))));
        
        double force_x[no_of_part];
        double force_y[no_of_part];
        double force_z[no_of_part];

        for(int i=0; i < no_of_part; i++){
                force_x[i] = 0;
                force_y[i] = 0;
                force_z[i] = 0;
        }
        for(int i=0; i < no_of_part; i++){
                for(int j=no_of_part-1; j > i; j--){
                        double distance = calc_dist(box_size, x_pos[i], x_pos[j], y_pos[i],
                                        y_pos[j], z_pos[i], z_pos[j]);
                        if(distance < cutoff_distance){
                                double force_mag = ((4 * epsilon) * (((12 * pow(sigma, 12))
                                                                      /(pow(distance, 13)))
                                        - ((6 * pow(sigma, 6))/(pow(distance, 7))))) - Frc;
                                double x_diff = x_pos[j]-x_pos[i];
                                double y_diff = y_pos[j]-y_pos[i];
                                double z_diff = z_pos[j]-z_pos[i];

                                double half_box_size = box_size/2;

                                if(fabs(x_diff) > half_box_size){
                                        if(x_diff > 0){
                                                x_diff = x_diff - box_size;
                                        } else{
                                                x_diff = box_size + x_diff;
                                        }
                                }
                                if(fabs(y_diff) > half_box_size){
                                        y_diff = y_diff - box_size;
                                }
                                if(fabs(z_diff) > half_box_size){
                                        z_diff = z_diff - box_size;
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
        memcpy(force_arr_x, force_x, sizeof(force_x));
        memcpy(force_arr_y, force_y, sizeof(force_y));
        memcpy(force_arr_z, force_z, sizeof(force_z));
}

void position_update(double x_pos[], double y_pos[], double z_pos[], double x_vel[], 
                double y_vel[], double z_vel[], double f_xt[], double f_yt[], 
                double f_zt[], double dt, double mass, int no_of_part, double box_size)
{
        double updated_x[no_of_part];
        double updated_y[no_of_part];
        double updated_z[no_of_part];
        
        double coeff = (0.5 * dt * dt)/mass;

        #pragma omp parallel for collapse(1)
        for(int i=0; i < no_of_part; i++){
                // Updating position using velocity verlet algorithm
                updated_x[i] = (x_pos[i] + (x_vel[i] * dt) + (f_xt[i] * coeff));
                updated_y[i] = (y_pos[i] + (y_vel[i] * dt) + (f_yt[i] * coeff));
                updated_z[i] = (z_pos[i] + (z_vel[i] * dt) + (f_zt[i] * coeff));
                
                // Applying PBC
                updated_x[i] = PBC(updated_x[i], box_size);
                updated_y[i] = PBC(updated_y[i], box_size);
                updated_z[i] = PBC(updated_z[i], box_size);
        }
        memcpy(x_pos, updated_x, sizeof(updated_x));
        memcpy(y_pos, updated_y, sizeof(updated_y));
        memcpy(z_pos, updated_z, sizeof(updated_z));
}

void velocity_update(double x_vel[], double y_vel[], double z_vel[], double f_xt[],
                double f_xtp1[], double f_yt[], double f_ytp1[], double f_zt[], 
                double f_ztp1[], double dt, double mass, int no_of_part)
{
        double updated_vx[no_of_part];
        double updated_vy[no_of_part];
        double updated_vz[no_of_part];

        double coeff = (0.5 * dt)/mass;

        #pragma omp parallel for collapse(1)
        for(int i=0; i < no_of_part; i++){
                // Updating velocity using velocity verlet algorithm
                updated_vx[i] = x_vel[i] + (f_xt[i] + f_xtp1[i]) * coeff;
                updated_vy[i] = y_vel[i] + (f_yt[i] + f_ytp1[i]) * coeff;
                updated_vz[i] = z_vel[i] + (f_zt[i] + f_ztp1[i]) * coeff;
        }
        memcpy(x_vel, updated_vx, sizeof(updated_vx));
        memcpy(y_vel, updated_vy, sizeof(updated_vy));
        memcpy(z_vel, updated_vz, sizeof(updated_vz));
}

double calculate_KE(double x_vel[], double y_vel[], double z_vel[], int no_of_part,
                double mass)
{
        double KE_tot = 0;
        double KE_mat[no_of_part];

        #pragma omp parallel for collapse(1)
        for(int i=0; i < no_of_part; i++){
                KE_mat[i] = (0.5 * mass * (pow(x_vel[i], 2) + pow(y_vel[i], 2) 
                                        + pow(z_vel[i], 2)));
        }
        for(int i=0; i < no_of_part; i++){
                KE_tot += KE_mat[i];
        }
        return (KE_tot/no_of_part);
}

double calculate_PE(double x_pos[], double y_pos[], double z_pos[], double cutoff_dist,
                int no_of_part, double box_size, double sigma, double epsilon)
{
        double Vrc = ((4 * epsilon) * ((pow((sigma/cutoff_dist), 12)) 
                                -(pow((sigma/cutoff_dist), 6))));

        double Frc = ((4 * epsilon) * (((12 * pow(sigma, 12))/(pow(cutoff_dist, 13)))
                        - ((6 * pow(sigma, 6))/(pow(cutoff_dist, 7)))));
        double shift = -(Vrc + (Frc * cutoff_dist));

        double PE_tot = 0;
        double pair_pot = 0;

        for(int i=0; i < no_of_part; i++){
                //#pragma omp parallel for collapse(1)
                for(int j=no_of_part-1; j > i; j--){
                        double dist = calc_dist(box_size, x_pos[i], x_pos[j], y_pos[i],
                                        y_pos[j], z_pos[i], z_pos[j]);
                        if(dist < cutoff_dist){
                               pair_pot = ((4 * epsilon) * ((pow((sigma/dist), 12)) 
                                -(pow((sigma/dist), 6)))) + (dist * Frc) + shift;
                               PE_tot += pair_pot;
                        }
                }
        }
        return (PE_tot/no_of_part);
}

int main()
{
        double begin = omp_get_wtime();

        srand(time(NULL));

        int n = 2197; // Number of particles
        double dt = 0.00005; // Integration time step
        double box_size = 20;
        double epsilon = 1; // Depth of potential minima
        double r_c = 2.5; // Cutoff radius
        double mass = 1;
        double KbT = 1;
        double sigma = 1; // Diameter of the particle

        double x_position[n];
        double y_position[n];
        double z_position[n];
        
        double x_velocity[n];
        double y_velocity[n];
        double z_velocity[n];

        double x_force[n];
        double y_force[n];
        double z_force[n];

        double x_force_new[n];
        double y_force_new[n];
        double z_force_new[n];

        FILE *fPtr;
        fPtr = fopen("KEq2.dat","w");

        FILE *fPt;
        fPt = fopen("PEq2.dat","w");

        double KE = 0;
        double PE = 0;

        initialize_positions(n, box_size, x_position, y_position, z_position);
        initialize_velocies(n, KbT, mass, x_velocity, y_velocity, z_velocity);

        force_calc(sigma, epsilon, x_position, y_position, z_position, r_c,
                        x_force, y_force, z_force, n, box_size);

        int n_iter = 2000;
        for(int i=0; i < n_iter; i++){
                position_update(x_position, y_position, z_position, x_velocity, y_velocity,
                                z_velocity, x_force, y_force, z_force, dt, mass, n, box_size);
                force_calc(sigma, epsilon, x_position, y_position, z_position, r_c,
                                x_force_new, y_force_new, z_force_new, n, box_size);
                velocity_update(x_velocity, y_velocity, z_velocity, x_force, x_force_new,
                                y_force, y_force_new, z_force, z_force_new, dt, mass, n);

                memcpy(x_force, x_force_new, sizeof(x_force_new));
                memcpy(y_force, y_force_new, sizeof(y_force_new));
                memcpy(z_force, z_force_new, sizeof(z_force_new));

                if(i%10 == 0){
                        KE = calculate_KE(x_velocity, y_velocity, z_velocity, n, mass);
                        PE = calculate_PE(x_position, y_position, z_position, r_c, n, box_size,
                                        sigma, epsilon);
                        fprintf(fPtr, "%f\n", KE);
                        fprintf(fPt, "%f\n", PE);
                }
        }
        fclose(fPtr);
        fclose(fPt);

        double end = omp_get_wtime();
        double time_spent = (end-begin);
        printf("\nSuccessfully finished running in %.8f s.\n",(end-begin));

        return 0;
}

