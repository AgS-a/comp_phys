import matplotlib.pyplot as plt
import numpy as np

eul = []
with open("eul1.dat","r") as eul_dat:
    for lines in eul_dat:
        eul.append(float(lines.strip()))

mod_eul = []
with open("mod_eul1.dat","r") as mod_eul_dat:
    for lines in mod_eul_dat:
        mod_eul.append(float(lines.strip()))

imp_eul = []
with open("imp_eul1.dat","r") as imp_eul_dat:
    for lines in imp_eul_dat:
        imp_eul.append(float(lines.strip()))

RK = []
with open("RK41.dat","r") as RK_dat:
    for lines in RK_dat:
        RK.append(float(lines.strip()))

x = np.linspace(0.001,1.55-0.001,len(eul))
plt.plot(x,eul,'.',label="Euler")
plt.plot(x,mod_eul,'.',label="Modified Euler")
plt.plot(x,imp_eul,'.',label="Improved Euler")
plt.plot(x,RK,'.',label="RK4")
plt.legend()
plt.grid(True)
plt.show()


