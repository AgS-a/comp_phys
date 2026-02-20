import matplotlib.pyplot as plt
import numpy as np

q3 = []
with open("q3.dat","r") as q3_dat:
    for lines in q3_dat:
        q3.append(float(lines.strip()))

plt.plot(q3,'-')
plt.title('Magnetization at each iteration(KbT=4.9,L=30)')
plt.ylabel('Magnetization')
plt.legend()
plt.show()

q4 = []
with open("q4.dat","r") as q4_dat:
    for lines in q4_dat:
        q4.append(float(lines.strip()))

plt.plot(q4,'-')
plt.ylabel('Energy per spin')
plt.show()

q5_mag = []
with open("q5_mag.dat","r") as q5_mag_dat:
    for lines in q5_mag_dat:
        q5_mag.append(float(lines.strip()))

plt.plot(q5_mag,'-')
plt.title('Magnetization at each iteration(KbT=4.05,L=30)')
plt.ylabel('Magnetization')
plt.show()

q5_E = []
with open("q5_E.dat","r") as q5_E_dat:
    for lines in q5_E_dat:
        q5_E.append(float(lines.strip()))

plt.plot(q5_E,'-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_24 = []
with open("q6_mag_24.dat", "r") as q6_mag_24_dat:
    for lines in q6_mag_24_dat:
        q6_mag_24.append(float(lines.strip()))

plt.plot(q6_mag_24, '-')
plt.title('Magnetization at each iteration(KbT=3.9,L=24)')
plt.ylabel('Magnetization')
plt.show()

q6_E_24 = []
with open("q6_E_24.dat", "r") as q6_E_24_dat:
    for lines in q6_E_24_dat:
        q6_E_24.append(float(lines.strip()))

plt.plot(q6_E_24, '-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_30 = []
with open("q6_mag_30.dat", "r") as q6_mag_30_dat:
    for lines in q6_mag_30_dat:
        q6_mag_30.append(float(lines.strip()))

plt.plot(q6_mag_30, '-')
plt.title('Magnetization at each iteration(KbT=3.9,L=30)')
plt.ylabel('Magnetization')
plt.show()

q6_E_30 = []
with open("q6_E_30.dat", "r") as q6_E_30_dat:
    for lines in q6_E_30_dat:
        q6_E_30.append(float(lines.strip()))

plt.plot(q6_E_30, '-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_36 = []
with open("q6_mag_36.dat", "r") as q6_mag_36_dat:
    for lines in q6_mag_36_dat:
        q6_mag_36.append(float(lines.strip()))

plt.plot(q6_mag_36, '-')
plt.ylabel('Magnetization')
plt.title('Magnetization at each iteration(KbT=3.9,L=36)')
plt.show()

q6_E_36 = []
with open("q6_E_36.dat", "r") as q6_E_36_dat:
    for lines in q6_E_36_dat:
        q6_E_36.append(float(lines.strip()))

plt.plot(q6_E_36, '-')
plt.ylabel('Energy per spin')
plt.show()
