import matplotlib.pyplot as plt
import numpy as np
vx = []
with open("momen.dat","r") as dat:
    for lines in dat:
        vx.append(float(lines.strip()))

plt.xlabel("time")
plt.ylabel("total momentum")
plt.plot(vx,'.')
plt.show()
