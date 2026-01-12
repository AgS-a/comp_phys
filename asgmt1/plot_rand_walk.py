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

ran_wal_i = []

with open('sum_ran_walk.dat','r') as ra:
    for line in ra:
        ran_wal_i.append(int(line.strip()))

## Q1i ##

(mu,sigma) = norm.fit(ran_wal_i)
y = norm.pdf(bs(ran_wal_i,1),mu,sigma)
plt.plot(bs(ran_wal_i,1),y,'r--',linewidth=2)

plt.hist(ran_wal_i,bins = bs(ran_wal_i,1),edgecolor='black',density=True)
plt.title(f'10ksteps, 10ksamples, bin size=1, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

## Q1j ##

(mu,sigma) = norm.fit(ran_wal_i)
y = norm.pdf(bs(ran_wal_i,2),mu,sigma)
plt.plot(bs(ran_wal_i,2),y,'r--',linewidth=2)

plt.hist(ran_wal_i,bins = bs(ran_wal_i,2),edgecolor='black',density=True)
plt.title(f'10ksteps, 10ksamples, bin size=2, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')
plt.show()

def integrate(start,end):
    n,bins, _ = plt.hist(ran_wal_i,bins = bs(ran_wal_i,2),edgecolor='black',density=True)
    binss = bs(ran_wal_i,2)
    for i in range(len(binss)):
        if start <= binss[i]:
            s = i-1
            break
    for i in range(len(binss)):
        if end <= binss[i]:
            e = i
            break
    bin_width = 2
    intt = bin_width * sum(n[s:e])
    return intt

print(integrate(-2,2))

bisize = bs(ran_wal_i,2)
shift = [(i-1) for i in bisize]
shift.append(shift[-1]+2)

y = norm.pdf(shift,mu,sigma)
plt.plot(shift,y,'r--',linewidth=2)

plt.hist(ran_wal_i,bins = shift,edgecolor='black',density=True)
plt.title(f'10ksteps, 10ksamples, bin size=2(centered at 0), $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

(mu,sigma) = norm.fit(ran_wal_i)
y = norm.pdf(bs(ran_wal_i,5),mu,sigma)
plt.plot(bs(ran_wal_i,5),y,'r--',linewidth=2)

plt.hist(ran_wal_i,bins = bs(ran_wal_i,5),edgecolor='black',density=True)
plt.title(f'10ksteps, 10ksamples, bin size=5, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

(mu,sigma) = norm.fit(ran_wal_i)
y = norm.pdf(bs(ran_wal_i,10),mu,sigma)
plt.plot(bs(ran_wal_i,10),y,'r--',linewidth=2)

plt.hist(ran_wal_i,bins = bs(ran_wal_i,10),edgecolor='black',density=True)
plt.title(f'10ksteps, 10ksamples, bin size=10, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

ran_wal_k = []

with open('q1k.dat','r') as rak:
    for line in rak:
        ran_wal_k.append(float(line.strip()))

## Q1k ##

(mu,sigma) = norm.fit(ran_wal_k)
y = norm.pdf(bs(ran_wal_k,10),mu,sigma)
plt.plot(bs(ran_wal_k,10),y,'r--',linewidth=2)
plt.hist(ran_wal_k,bins = bs(ran_wal_k,10),edgecolor='black',density=True)
plt.title(f'10ksteps, 100ksamples, bin size=10, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

ran_wal_l = []

with open('q1l.dat','r') as ral:
    for line in ral:
        ran_wal_l.append(float(line.strip()))

## Q1l ##

(mu,sigma) = norm.fit(ran_wal_l)
y = norm.pdf(bs(ran_wal_l,10),mu,sigma)
plt.plot(bs(ran_wal_l,10),y,'r--',linewidth=2)
plt.hist(ran_wal_l,bins = bs(ran_wal_l,10),edgecolor='black',density=True)
plt.title(f'100ksteps, 100ksamples, bin size=10, $\mu$={mu:.2f}, $\sigma$={sigma:.2f}')
plt.xlabel('End Point')
plt.ylabel('normalized pdf')

plt.show()

