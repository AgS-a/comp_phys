import matplotlib.pyplot as plt
import pandas as pd

# 1. Read the exported CSV data
try:
    df = pd.read_csv('histogram_data.csv')
except FileNotFoundError:
    print("Error: 'histogram_data.csv' not found. Run the C program first!")
    exit()

# 2. Extract data for plotting
bin_centers = df['Bin_Center']
frequencies = df['Frequency']
# Calculate bin width from the first two centers to set bar width correctly
bin_width = bin_centers[1] - bin_centers[0]

# 3. Plotting
plt.figure(figsize=(10, 6))
plt.bar(bin_centers, frequencies, width=bin_width * 0.9, color='skyblue', edgecolor='black', alpha=0.7)

# 4. Styling
plt.title('Histogram of Data (Processed in C)', fontsize=14)
plt.xlabel('Value Range', fontsize=12)
plt.ylabel('Frequency', fontsize=12)
plt.grid(axis='y', linestyle='--', alpha=0.5)

# 5. Show/Save
plt.savefig('histogram_output.png') # Optional: Save to file
print("Plot saved as histogram_output.png")
plt.show()
