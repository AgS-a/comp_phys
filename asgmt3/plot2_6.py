import matplotlib.pyplot as plt
import numpy as np

q3 = []
with open("q3.dat","r") as q3_dat:
    for lines in q3_dat:
        q3.append(float(lines.strip()))

plt.plot(q3,'-')
plt.title('Magnetization at each iteration(KbT=4.9,L=10)')
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
plt.title('Magnetization at each iteration(KbT=4.05,L=10)')
plt.ylabel('Magnetization')
plt.show()

q5_E = []
with open("q5_E.dat","r") as q5_E_dat:
    for lines in q5_E_dat:
        q5_E.append(float(lines.strip()))

plt.plot(q5_E,'-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_8 = []
with open("q6_mag_8.dat", "r") as q6_mag_8_dat:
    for lines in q6_mag_8_dat:
        q6_mag_8.append(float(lines.strip()))

plt.plot(q6_mag_8, '-')
plt.title('Magnetization at each iteration(KbT=3.9,L=8)')
plt.ylabel('Magnetization')
plt.show()

q6_E_8 = []
with open("q6_E_8.dat", "r") as q6_E_8_dat:
    for lines in q6_E_8_dat:
        q6_E_8.append(float(lines.strip()))

plt.plot(q6_E_8, '-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_10 = []
with open("q6_mag_10.dat", "r") as q6_mag_10_dat:
    for lines in q6_mag_10_dat:
        q6_mag_10.append(float(lines.strip()))

plt.plot(q6_mag_10, '-')
plt.title('Magnetization at each iteration(KbT=3.9,L=10)')
plt.ylabel('Magnetization')
plt.show()

q6_E_10 = []
with open("q6_E_10.dat", "r") as q6_E_10_dat:
    for lines in q6_E_10_dat:
        q6_E_10.append(float(lines.strip()))

plt.plot(q6_E_10, '-')
plt.ylabel('Energy per spin')
plt.show()

q6_mag_12 = []
with open("q6_mag_12.dat", "r") as q6_mag_12_dat:
    for lines in q6_mag_12_dat:
        q6_mag_12.append(float(lines.strip()))

plt.plot(q6_mag_12, '-')
plt.ylabel('Magnetization')
plt.show()

q6_E_12 = []
with open("q6_E_12.dat", "r") as q6_E_12_dat:
    for lines in q6_E_12_dat:
        q6_E_12.append(float(lines.strip()))

plt.plot(q6_E_12, '-')
plt.ylabel('Energy per spin')
plt.show()
