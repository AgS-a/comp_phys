import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import maxwell

data = np.loadtxt('vel.dat')

vx, vy, vz = data[:, 0], data[:, 1], data[:, 2]
speeds = np.sqrt(vx**2 + vy**2 + vz**2)

densities, bin_edges = np.histogram(speeds, bins=30, density=True)
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

plt.plot(bin_centers, densities, '.', color='black', alpha=0.8, zorder=3, label='Freq of speeds')

loc, scale = maxwell.fit(speeds, floc=0)
kbt = scale**2 

vp = np.sqrt(2) * scale

x_axis = np.linspace(0, np.max(speeds) * 1.2, 200)
mb_fit = maxwell.pdf(x_axis, loc=loc, scale=scale)

plt.plot(x_axis, mb_fit, 'r-', lw=2.5, zorder=2, label=f'Maxwell-Boltzmann Fit\n($k_BT \\approx$ {kbt:.3f})')

plt.axvline(vp, color='gray', linestyle=':', lw=2, zorder=2, label=f'Most Probable Speed ($\\approx$ {vp:.3f})')

plt.xlabel("Speed (v)")
plt.ylabel("Probability Density")
plt.title("Maxwell-Boltzmann distribution")
plt.legend()
plt.grid(True, alpha=0.3, zorder=1)

plt.tight_layout()
plt.show()
