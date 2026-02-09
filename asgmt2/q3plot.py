import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

gaussian = []
expo = []

with open("gau.dat","r") as gau:
    for line in gau:
        gaussian.append(float(line.strip()))

with open("exp.dat","r") as exp:
    for line in exp:
        expo.append(float(line.strip()))

def bs(lis,x):
    bin_size = x
    min_edge = min(lis)
    max_edge = max(lis)
    N = int((max_edge - min_edge) / bin_size)
    Nplus1 = N + 1
    bin_edges = np.linspace(min_edge, max_edge, Nplus1)
    return bin_edges

def expo_dist(x, alpha):
    return alpha * np.exp(-alpha * x)

def gaussian_pdf(x, mu, sigma):
    return (1 / (sigma * np.sqrt(2 * np.pi))) * np.exp(-0.5 * ((x - mu) / sigma)**2)

plt.figure(figsize=(8, 6))

counts, bins, _ = plt.hist(expo, bins=bs(expo, 0.1), edgecolor='black', density=True)
bin_centers = (bins[:-1] + bins[1:]) / 2

popt_e, _ = curve_fit(expo_dist, bin_centers, counts)

x_fit = np.linspace(min(expo), max(expo), 1000)
plt.plot(x_fit, expo_dist(x_fit, *popt_e), 'r-', linewidth=2, label=f'Fit: $\\alpha$={popt_e[0]:.2f}')
plt.ylabel('PDF')
plt.title('Sampling random numbers from an exponential distribution(inverse)')
plt.legend()
plt.show()

plt.figure(figsize=(8, 6))

counts, bins, _ = plt.hist(gaussian, bins=bs(gaussian, 0.2), edgecolor='black', density=True)
bin_centers = (bins[:-1] + bins[1:]) / 2

popt_g, _ = curve_fit(gaussian_pdf, bin_centers, counts, p0=[0, 1])

x_fit = np.linspace(min(gaussian), max(gaussian), 1000)
plt.plot(x_fit, gaussian_pdf(x_fit, *popt_g), 'r-', linewidth=2, label=f'Fit: $\mu$={popt_g[0]:.2f}, $\sigma$={popt_g[1]:.2f}')

plt.title('Sampling random numbers from a normal distribution(box-muller)')
plt.legend()
plt.ylabel('PDF')
plt.show()
