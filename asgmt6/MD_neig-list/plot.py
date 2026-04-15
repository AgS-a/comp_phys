import matplotlib.pyplot as plt

pcfl = []
with open("pair_cf.dat","r") as pcf:
    for lines in pcf:
        pcfl.append(float(lines.strip()))

plt.plot(pcfl,'.')
plt.show()


mb = []
with open("mb.dat","r") as mb_dat:
    for lines in mb_dat:
        mb.append(float(lines.strip()))

plt.plot(mb,'.')
plt.show()
