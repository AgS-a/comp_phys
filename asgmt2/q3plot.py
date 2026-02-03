import matplotlib.pyplot as plt
import numpy as np

gaussian = []
expo = []

with open("gau.dat","r") as gau:
    for line in gau:
        gaussian.append(float(line.strip()))

with open("exp.dat","r") as exp:
    for line in exp:
        expo.append(float(line.strip()))
'''
xd = []
with open("x.dat","r") as x:
    for line in x:
        xd.append(float(line.strip()))
'''
def bs(lis,x):
    bin_size = x
    min_edge = min(lis)
    max_edge = max(lis)
    N = int((max_edge - min_edge) / bin_size)
    Nplus1 = N + 1
    bin_edges = np.linspace(min_edge, max_edge, Nplus1)
    return bin_edges

plt.hist(expo,bins = bs(expo,0.1), edgecolor='black', density=True)
plt.title('Sampling random numbers from an exponential distribution(inverse)')
plt.show()

plt.hist(gaussian,bins = bs(gaussian,0.2), edgecolor='black', density=True)
plt.title('Sampling random numbers from a normal distribution(box-muller)')
plt.show()

#plt.plot(xd,gaussian,'.')
#plt.show()

