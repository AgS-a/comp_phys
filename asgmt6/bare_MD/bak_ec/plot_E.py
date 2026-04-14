import matplotlib.pyplot as plt

KE = []
with open("KEq2.dat","r") as ke_dat:
    for lines in ke_dat:
        KE.append(float(lines.strip()))

PE = []
with open("PEq2.dat","r") as pe_dat:
    for lines in pe_dat:
        PE.append(float(lines.strip()))

TE =[]

for i in range(len(PE)):
    TE.append(KE[i] + PE[i])

#plt.plot(KE,'.',label="KE")
#plt.plot(PE,'.',label="PE")
plt.plot(TE,'.',label="TE")

plt.legend()
plt.grid(True)
plt.show()
