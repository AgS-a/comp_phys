import matplotlib.pyplot as plt
import numpy as np

def plot_bands(filename):
    testlist = []
    with open(filename,"r") as test1dat:
        for lines in test1dat:
            testlist.append(lines.strip())

    testsplit = [i.split('    ') for i in testlist]

    k_pts = []
    E1 = []
    E2 = []
    E3 = []

    for i in range(len(testsplit)):
        k_pts.append(float(testsplit[i][0]))
        E1.append(float(testsplit[i][1]))
        E2.append(float(testsplit[i][2]))
        E3.append(float(testsplit[i][3]))

    plt.plot(k_pts,E1)
    plt.plot(k_pts,E2)
    plt.plot(k_pts,E3)
    plt.show()

plot_bands("a1.50_Vo0.50_nk401_ng3.dat")
plot_bands("a1.50_Vo0.00_nk401_ng3.dat")
