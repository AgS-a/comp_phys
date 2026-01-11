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

ran_wal = []

with open('sum_ran_walk.dat','r') as ra:
    for line in ra:
        ran_wal.append(float(line.strip()))

plt.hist(ran_wal,bins = bs(ran_wal,10),edgecolor='black',density=True)
plt.show()
