import matplotlib.pyplot as plt
import numpy as np

pcfl = []
with open("pair_cf.dat","r") as pcf:
    for lines in pcf:
        pcfl.append(float(lines.strip()))

dr = 0.05
x_pcfl = np.arange(0,len(pcfl),1)
x_pcfl = x_pcfl * dr

plt.plot(x_pcfl, pcfl, '.')
plt.grid(True)
plt.show()


mb = []
with open("mb.dat","r") as mb_dat:
    for lines in mb_dat:
        mb.append(float(lines.strip()))

dv = 0.05
x_mb = np.arange(0,len(mb),1)
x_mb = x_mb * dv
plt.plot(x_mb, mb, '.')
plt.grid(True)
plt.show()
