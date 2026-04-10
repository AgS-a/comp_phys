import matplotlib.pyplot as plt

KE = []
with open("KEq2.dat","r") as ke_dat:
    for lines in ke_dat:
        KE.append(float(lines.strip()))

PE = []
with open("PEq2.dat","r") as pe_dat:
    for lines in pe_dat:
        PE.append(float(lines.strip()))

plt.plot(KE,'.')
plt.plot(PE,'.')
plt.show()
