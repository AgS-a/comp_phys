import matplotlib.pyplot as plt

x1 = []
with open("sinx_x00.0000.dat","r") as x1_dat:
    for lines in x1_dat:
        x1.append(float(lines.strip()))
x2 = []
with open("sinx_x00.1000.dat","r") as x2_dat:
    for lines in x2_dat:
        x2.append(float(lines.strip()))

plt.plot(x1)
plt.plot(x2)
plt.show()

v1 = []
with open("sinx_v01.9000.dat") as v1_dat:
    for lines in v1_dat:
        v1.append(float(lines.strip()))
v2 = []
with open("sinx_v01.9900.dat") as v2_dat:
    for lines in v2_dat:
        v2.append(float(lines.strip()))

plt.plot(v1)
plt.plot(v2)
plt.show()
