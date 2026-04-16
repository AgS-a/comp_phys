import matplotlib.pyplot as plt
import numpy as np

pcfl_1200 = []
with open("./1200part/pair_cf.dat", "r") as pcf:
    for lines in pcf:
        pcfl_1200.append(float(lines.strip()))

pcfl_2400 = []
with open("./2400part/pair_cf.dat", "r") as pcf:
    for lines in pcf:
        pcfl_2400.append(float(lines.strip()))

pcfl_3600 = []
with open("./3600part/pair_cf.dat", "r") as pcf:
    for lines in pcf:
        pcfl_3600.append(float(lines.strip()))

dr = 0.05
x_pcfl = np.arange(0, len(pcfl_1200), 1) * dr


plt.figure(figsize=(8, 5))
plt.plot(x_pcfl, pcfl_1200, '.',label="1200 part")
plt.plot(x_pcfl, pcfl_2400, '.',label="2400 part")
plt.plot(x_pcfl, pcfl_3600, '.',label="3600 part")

plt.title("Pair Correlation Function")
plt.xlabel("Distance (r)")
plt.ylabel("g(r)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
