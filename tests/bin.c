#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_FILE "q1l.dat"
#define OUTPUT_FILE "histogram_data.csv"
#define NUM_BINS 50

int main()
{
        FILE *file;
        double value;
        double min_val = 1e9, max_val = -1e9;
        int bins[NUM_BINS] = { 0 };
        int count = 0;

        // --- PASS 1: Find Min and Max ---
        file = fopen(INPUT_FILE, "r");

        while (fscanf(file, "%lf", &value) == 1) {
                if (value < min_val)
                        min_val = value;
                if (value > max_val)
                        max_val = value;
                count++;
        }

        // Add a small epsilon to max_val to ensure the largest value falls in the last bin instead of creating an out-of-bounds index.
        double safe_max = max_val + 1e-9;
        double bin_width = (safe_max - min_val) / NUM_BINS;

        printf("Range: [%.2f, %.2f], Bin Width: %.4f\n", min_val, max_val,
               bin_width);

        // --- PASS 2: Binning the Data ---
        rewind(file);           // Go back to start of file

        while (fscanf(file, "%lf", &value) == 1) {
                int bin_index = (int)((value - min_val) / bin_width);

                // Safety check for indices (though safe_max handles most cases)
                if (bin_index >= NUM_BINS)
                        bin_index = NUM_BINS - 1;
                if (bin_index < 0)
                        bin_index = 0;

                bins[bin_index]++;
        }
        fclose(file);

        // --- Export to CSV ---
        file = fopen(OUTPUT_FILE, "w");

        // Write Header
        fprintf(file, "Bin_Center,Frequency\n");

        for (int i = 0; i < NUM_BINS; i++) {
                double bin_center =
                    min_val + (i * bin_width) + (bin_width / 2.0);
                fprintf(file, "%f,%d\n", bin_center, bins[i]);
        }

        fclose(file);

        return 0;
}
