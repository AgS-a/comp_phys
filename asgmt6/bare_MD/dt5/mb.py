import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import maxwell

# 1. Load the data from the text file
# Replace 'velocities.txt' with the actual path to your file
try:
    # numpy.loadtxt automatically handles whitespace/tabs between columns
    data = np.loadtxt('vel.dat')
except FileNotFoundError:
    print("Error: 'velocities.txt' not found. Please check the file path.")
    exit()

# 2. Extract velocity components
vx = data[:, 0]
vy = data[:, 1]
vz = data[:, 2]

# 3. Calculate the speed for each particle
# Speed is the magnitude of the velocity vector
speeds = np.sqrt(vx**2 + vy**2 + vz**2)

# 4. Plot the histogram of the calculated speeds
# density=True normalizes the histogram so the total area is 1, 
# which is necessary to overlay a probability density function (PDF)
plt.hist(speeds, bins=30, density=True, alpha=0.6, color='skyblue', edgecolor='black', label='Simulation Speeds')

# 5. Fit a Maxwell-Boltzmann distribution to the data
# We force the location (floc) to 0 since speed cannot be negative
loc, scale = maxwell.fit(speeds, floc=0)

# Generate x-values for plotting the theoretical curve
# We extend the x-axis slightly beyond the maximum speed for a clean plot
x_axis = np.linspace(0, np.max(speeds) * 1.2, 200)

# Calculate the theoretical Maxwell-Boltzmann probability density function (PDF)
mb_fit = maxwell.pdf(x_axis, loc=loc, scale=scale)

# Plot the theoretical curve
plt.plot(x_axis, mb_fit, 'r-', lw=2.5, label=f'Maxwell-Boltzmann Fit\n(scale parameter $\\sigma \\approx$ {scale:.3f})')

# 6. Formatting the plot
plt.xlabel("Speed (v)")
plt.ylabel("Probability Density")
plt.title("Speed Distribution vs. Maxwell-Boltzmann")
plt.legend()
plt.grid(True, alpha=0.3)

# Display the plot
plt.tight_layout()
plt.show()
