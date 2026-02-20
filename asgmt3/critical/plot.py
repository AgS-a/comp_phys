import matplotlib.pyplot as plt

mag = []
with open("critical_mag.dat","r") as mag_dat:
    for lines in mag_dat:
        mag.append(float(lines.strip()))

E = []
with open("critical_E.dat","r") as E_dat:
    for lines in E_dat:
        E.append(float(lines.strip()))

plt.plot(mag,'-')
plt.show()

plt.plot(E,'-')
plt.show()
