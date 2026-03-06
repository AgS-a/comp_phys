import matplotlib.pyplot as plt
import numpy as np

eul = []
with open("eul1.dat","r") as eul_dat:
    for lines in eul_dat:
        eul.append(float(lines.strip()))

x = np.linspace(0.001,1.55-0.001,len(eul))
plt.plot(x,eul,'.')
plt.show()
