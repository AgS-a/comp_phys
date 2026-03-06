import matplotlib.pyplot as plt
import math

cai26 = []
with open("cai_L26_m.dat","r") as cai26_dat:
    for lines in cai26_dat:
        cai26.append(float(lines.strip()))

cai30 = []
with open("cai_L30_m.dat","r") as cai30_dat:
    for lines in cai30_dat:
        cai30.append(float(lines.strip()))

cai36 = []
with open("cai_L36_m.dat","r") as cai36_dat:
    for lines in cai36_dat:
        cai36.append(float(lines.strip()))

cv26 = []
with open("cv_L26_m.dat","r") as cv26_dat:
    for lines in cv26_dat:
        cv26.append(float(lines.strip()))

cv30 = []
with open("cv_L30_m.dat","r") as cv30_dat:
    for lines in cv30_dat:
        cv30.append(float(lines.strip()))

cv36 = []
with open("cv_L36_m.dat","r") as cv36_dat:
    for lines in cv36_dat:
        cv36.append(float(lines.strip()))

T = []
for i in range(71):
    T.append(3.3+(0.02*i))

plt.plot(T,cai26,'.',label='L=26')
plt.plot(T,cai30,'.',label='L=30')
plt.plot(T,cai36,'.',label='L=36')
plt.legend()
plt.grid(True)
plt.xlabel('Temperature(reduced units)')
plt.ylabel('Average magnetization per spin')
plt.title('M per spin vs T')
plt.show()

plt.plot(T,cv26,'.',label='L=26')
plt.plot(T,cv30,'.',label='L=30')
plt.plot(T,cv36,'.',label='L=36')
'''
# --- New Code Start ---
# Find T corresponding to max Cv for the largest system (L=36)
max_cv_val = max(cv36)
max_cv_index = cv36.index(max_cv_val)
T_max = T[max_cv_index]

# Theoretical Tc for triangular lattice = 4 / ln(3)
Tc_theory = 4.0 / math.log(3)

# Add vertical dotted lines
plt.axvline(x=T_max, color='k', linestyle=':', label='Max Cv (L=36)')
plt.axvline(x=Tc_theory, color='r', linestyle=':', label='Theoretical Tc')
# --- New Code End ---
'''
plt.legend()
plt.grid(True)
plt.xlabel('Temperature(reduced units)')
plt.ylabel('Average energy per spin')
plt.title('E per spin vs T')
plt.show()
