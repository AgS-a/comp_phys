import matplotlib.pyplot as plt

bad_rn = []
with open("bad_random_numbers.dat","r") as brn:
    for lines in brn:
        bad_rn.append(float(lines.strip()))

plt.hist(bad_rn,bins=25,edgecolor='black')
plt.show()

good_rn = []
with open("random.dat","r") as grn:
    for lines in grn:
        good_rn.append(float(lines.strip()))

plt.hist(good_rn,bins=25,edgecolor='black')
plt.show()
