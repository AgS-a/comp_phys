import matplotlib.pyplot as plt
import numpy as np
import math

def bs(lis,x):
    bin_size = x
    min_edge = min(lis)
    max_edge = max(lis)
    N = int((max_edge - min_edge) / bin_size)
    Nplus1 = N + 1
    bin_edges = np.linspace(min_edge, max_edge, Nplus1)
    return bin_edges

def bin_sizes(x):
    return bs(sum_of_ran_nos,x)

sum_of_ran_nos = []

with open('dist_sum_10k.dat','r') as fil:
    for line in fil:
        sum_of_ran_nos.append(float(line.strip()))

#plt.hist(sum_of_ran_nos,bins=50,edgecolor='black')

plt.hist(sum_of_ran_nos,bins=bin_sizes(10),edgecolor='black')
plt.show()

plt.hist(sum_of_ran_nos,bins=bin_sizes(2),edgecolor='black',density=True)
plt.show()

plt.hist(sum_of_ran_nos,bins=bin_sizes(1),edgecolor='black',density=True)
plt.show()

plt.hist(sum_of_ran_nos,bins=bin_sizes(0.5),edgecolor='black',density=True)
plt.show()

omoh_l = []
omot_l = []

with open('omoh.dat','r') as omoh:
    for line in omoh:
        omoh_l.append(float(line.strip()))

with open('omot.dat','r') as omot:
    for line in omot:
        omot_l.append(float(line.strip()))
plt.hist(omot_l,bins=bs(omot_l,2),edgecolor='black',density=True)
plt.hist(omoh_l,bins=bs(omoh_l,2),edgecolor='black',density=True)
plt.show()
