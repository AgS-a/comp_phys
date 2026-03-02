import matplotlib.pyplot as plt

cai26 = []
with open("cai_L26.dat","r") as cai26_dat:
    for lines in cai26_dat:
        cai26.append(float(lines.strip()))

cai30 = []
with open("cai_L30.dat","r") as cai30_dat:
    for lines in cai30_dat:
        cai30.append(float(lines.strip()))

cai36 = []
with open("cai_L36.dat","r") as cai36_dat:
    for lines in cai36_dat:
        cai36.append(float(lines.strip()))

cv26 = []
with open("cv_L26.dat","r") as cv26_dat:
    for lines in cv26_dat:
        cv26.append(float(lines.strip()))

cv30 = []
with open("cv_L30.dat","r") as cv30_dat:
    for lines in cv30_dat:
        cv30.append(float(lines.strip()))

cv36 = []
with open("cv_L36.dat","r") as cv36_dat:
    for lines in cv36_dat:
        cv36.append(float(lines.strip()))

T = []
for i in range(71):
    T.append(3.3+(0.02*i))

plt.plot(T,cai26,'.',label='L=26')
plt.grid(True)
#plt.title(f'$\\chi$ vs T for L=26')
#plt.xlabel('Temperature(Reduced units)')
#plt.ylabel(f'$\\chi$')
#plt.show()

plt.plot(T,cai30,'.',label='L=30')
#plt.grid(True)
plt.title(f'$\\chi$ vs T')
#plt.xlabel('Temperature(Reduced units)')
#plt.ylabel(f'$\\chi$')
#plt.show()

plt.plot(T,cai36,'.',label='L=36')
#plt.grid(True)
#plt.title(f'$\\chi$ vs T for L=36')
plt.xlabel('Temperature(Reduced units)')
plt.ylabel(f'$\\chi$')
plt.legend()
plt.show()

plt.plot(T,cv26,'.',label='L=26')
#plt.grid(True)
#plt.title(f'$C_v$ vs T for L=26')
#plt.xlabel('Temperature(Reduced units)')
#plt.ylabel(f"$C_v$")
#plt.show()

plt.plot(T,cv30,'.',label='L=30')
#plt.grid(True)
#plt.title(f'$C_v$ vs T fot L=30')
#plt.xlabel('Temperature(Reduced units)')
#plt.ylabel(f"$C_v$")
#plt.show()

plt.plot(T,cv36,'.',label='L=36')
plt.grid(True)
plt.legend()
plt.title(f'$C_v$ vs T')
plt.xlabel('Temperature(Reduced units)')
plt.ylabel(f"$C_v$")
plt.show()

binder26 = []
with open("binder_L26.dat","r") as binder26_dat:
    for lines in binder26_dat:
        binder26.append(float(lines.strip()))

binder30 = []
with open("binder_L30.dat","r") as binder30_dat:
    for lines in binder30_dat:
        binder30.append(float(lines.strip()))

binder36 = []
with open("binder_L36.dat","r") as binder36_dat:
    for lines in binder36_dat:
        binder36.append(float(lines.strip()))

plt.plot(T,binder26,'.',label='L=26')
plt.plot(T,binder30,'.',label='L=30')
plt.plot(T,binder36,'.',label='L=36')
plt.legend()
plt.grid(True)
plt.title('Binders cumulant plot')
plt.ylabel(rf'$1 - \frac{{\langle M^4 \rangle}}{{3 \langle M^2 \rangle^2}}$')
plt.xlabel('Temperature(Reduced units)')
plt.show()
