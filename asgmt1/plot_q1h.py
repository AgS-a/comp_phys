import matplotlib.pyplot as plt
import numpy as np
import math
from scipy.stats import norm

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

(mu,sigma) = norm.fit(sum_of_ran_nos)
y = norm.pdf(bs(sum_of_ran_nos,10),mu,sigma)
plt.plot(bs(sum_of_ran_nos,10),y,'r--',linewidth=2)

plt.hist(sum_of_ran_nos,bins=bin_sizes(10),edgecolor='black')
plt.title(f'10knumbers, 10ksamples, bin size=10, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('Sum')
plt.ylabel('pdf(not normalized)')

plt.show()

(mu,sigma) = norm.fit(sum_of_ran_nos)
y = norm.pdf(bs(sum_of_ran_nos,2),mu,sigma)
plt.plot(bs(sum_of_ran_nos,2),y,'r--',linewidth=2)

plt.hist(sum_of_ran_nos,bins=bin_sizes(2),edgecolor='black',density=True)
plt.title(f'10knumbers, 10ksamples, bin size=2, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('Sum')
plt.ylabel('pdf(normalized)')

plt.show()

(mu,sigma) = norm.fit(sum_of_ran_nos)
y = norm.pdf(bs(sum_of_ran_nos,1),mu,sigma)
plt.plot(bs(sum_of_ran_nos,1),y,'r--',linewidth=2)

plt.hist(sum_of_ran_nos,bins=bin_sizes(1),edgecolor='black',density=True)
plt.title(f'10knumbers, 10ksamples, bin size=1, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('Sum')
plt.ylabel('pdf(normalized)')

plt.show()

(mu,sigma) = norm.fit(sum_of_ran_nos)
y = norm.pdf(bs(sum_of_ran_nos,0.5),mu,sigma)
plt.plot(bs(sum_of_ran_nos,0.5),y,'r--',linewidth=2)

plt.hist(sum_of_ran_nos,bins=bin_sizes(0.5),edgecolor='black',density=True)
plt.title(f'10knumbers, 10ksamples, bin size=0.5, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('Sum')
plt.ylabel('pdf(normalized)')

plt.show()

omoh_l = []
omot_l = []

with open('omoh.dat','r') as omoh:
    for line in omoh:
        omoh_l.append(float(line.strip()))

with open('omot.dat','r') as omot:
    for line in omot:
        omot_l.append(float(line.strip()))
plt.hist(omot_l,bins=bs(omot_l,2),edgecolor='black',density=True,label='10000')
plt.hist(omoh_l,bins=bs(omoh_l,2),edgecolor='black',density=True,label='100000')
plt.title('sum of 10k numbers 10k and 100k times')
plt.xlabel('Sum')
plt.ylabel('pdf(normalized)')
plt.legend()
plt.show()
