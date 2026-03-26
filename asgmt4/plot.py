import matplotlib.pyplot as plt
import numpy as np

## Question 1 ##

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
plt.title(f"Solutions of $y'=y^{2}+1$  using different methods")
plt.xlabel('x')
plt.ylabel('y(x)')
plt.legend()
plt.grid(True)
plt.show()

## Question 5 ##

x1 = []
with open("sinx_x00.0000.dat","r") as x1_dat:
    for lines in x1_dat:
        x1.append(float(lines.strip()))
x2 = []
with open("sinx_x00.1000.dat","r") as x2_dat:
    for lines in x2_dat:
        x2.append(float(lines.strip()))
x3 = []
with open("sinx_x00.0100.dat","r") as x3_dat:
    for lines in x3_dat:
        x3.append(float(lines.strip()))

plt.plot(x2,'.',label="x0=0.1,v0=1.9")
plt.plot(x1,'.',label="x0=0,v0=1.999")
plt.plot(x3,'.',label="x0=0.01,v0=2.1")
plt.legend()
plt.grid(True)
plt.xlabel('Time')
plt.ylabel('Position')
plt.title(r"x(t) for $\frac{d^{2}x}{dt^{2}} = -sin(x)$")
plt.show()

v1 = []
with open("sinx_v01.9000.dat") as v1_dat:
    for lines in v1_dat:
        v1.append(float(lines.strip()))
v2 = []
with open("sinx_v01.9900.dat") as v2_dat:
    for lines in v2_dat:
        v2.append(float(lines.strip()))
v3 = []
with open("sinx_v02.1000.dat") as v3_dat:
    for lines in v3_dat:
        v3.append(float(lines.strip()))

plt.plot(v1,'.',label="v0=1.9,x0=0.1")
plt.plot(v2,'.',label="v0=1.999,x0=0")
plt.plot(v3,'.',label="v0=2.1,x0=0.01")
plt.legend()
plt.grid(True)
plt.xlabel('Time')
plt.ylabel('Velocity')
plt.title(r"v(t) for $\frac{d^{2}x}{dt^{2}} = -sin(x)$")
plt.show()

## Question 8 ##

datl8 = []
with open("trial_posy1.dat","r") as datl8_temp:
    for lines in datl8_temp:
        datl8.append(float(lines.strip()))

plt.plot(datl8,'.')
print(datl8[1999])
plt.title("Trajectory of the 1st particle in the spring mass system")
plt.grid(True)
plt.xlabel('Time')
plt.ylabel('y(t) for 1st particle')
plt.show()

## Question 9 ##

dat_q9 = []
with open("trial_q9.dat","r") as dat_9_tmp:
    for lines in dat_9_tmp:
        dat_q9.append(float(lines.strip()))

plt.plot(dat_q9,'.',label="y(0)=0,y(1)=2")
plt.legend()
plt.grid(True)
plt.xlabel('x')
plt.ylabel('y(x)')
plt.title(f"Boundary value problem (y''-5y'+10y = 10x)")
plt.show()
