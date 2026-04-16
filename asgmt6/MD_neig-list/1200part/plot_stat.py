import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit
from scipy.signal import find_peaks

pcfl = []
with open("pair_cf.dat", "r") as pcf:
    for lines in pcf:
        pcfl.append(float(lines.strip()))

dr = 0.05
x_pcfl = np.arange(0, len(pcfl), 1) * dr
pcfl_arr = np.array(pcfl)

peaks, _ = find_peaks(pcfl_arr, prominence=0.01)
first_three_peaks = peaks[:3]

plt.figure(figsize=(8, 5))
plt.plot(x_pcfl, pcfl_arr, '.')

colors = ['red', 'green', 'purple']
for i, peak_idx in enumerate(first_three_peaks):
    peak_x = x_pcfl[peak_idx]
    peak_y = pcfl_arr[peak_idx]
    plt.axvline(peak_x, color=colors[i], linestyle=':', lw=2, 
                label=f'Peak {i+1} (r $\\approx$ {peak_x:.2f}, height $\\approx$ {peak_y:.2f})')

plt.title("Pair Correlation Function")
plt.xlabel("Distance (r)")
plt.ylabel("g(r)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

mb = []
with open("mb.dat", "r") as mb_dat:
    for lines in mb_dat:
        mb.append(float(lines.strip()))

dv = 0.05
x_mb = np.arange(0, len(mb), 1) * dv
mb = np.array(mb)

def mb_equation(v, a, A):
    return A * np.sqrt(2/np.pi) * (v**2 / a**3) * np.exp(-v**2 / (2*a**2))

popt, pcov = curve_fit(mb_equation, x_mb, mb, p0=[1.0, 1.0])
a_fit, A_fit = popt

kbt = a_fit**2
vp = np.sqrt(2) * a_fit

mb_fit = mb_equation(x_mb, a_fit, A_fit)

plt.figure(figsize=(8, 5))
plt.plot(x_mb, mb, '.', color='black', label='Freq of speeds')
plt.plot(x_mb, mb_fit, 'r-', lw=2.5, label=f'Maxwell-Boltzmann Fit\n($k_BT \\approx$ {kbt:.3f})')
plt.axvline(vp, color='gray', linestyle=':', lw=2, label=f'Most Probable Speed ($\\approx$ {vp:.3f})')

plt.xlabel("Speed (v)")
plt.ylabel("probability")
plt.title("Maxwell-Boltzmann distribution")
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()
