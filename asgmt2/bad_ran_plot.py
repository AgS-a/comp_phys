import matplotlib.pyplot as plt
import numpy as np

bad_rn = []
with open("bad_random_numbers.dat","r") as brn:
    for lines in brn:
        bad_rn.append(float(lines.strip()))

bad_rn_y = bad_rn[1:]
bad_rn_y.append(bad_rn[0])
plt.plot(bad_rn,bad_rn_y,'.')
plt.title('Scatter plot of bad rnd nos(lag=1)')
plt.xlabel('Bad random numbers')
plt.ylabel('list with lag=1')
plt.show()

plt.hist(bad_rn,bins=25,edgecolor='black')
plt.title('histogram of bad random numbers')
plt.ylabel('counts')
plt.show()

good_rn = []
with open("random.dat","r") as grn:
    for lines in grn:
        good_rn.append(float(lines.strip()))

good_rn_y = good_rn[1:]
good_rn_y.append(good_rn[0])
plt.plot(good_rn,good_rn_y,'.')

plt.xlabel('Good random numbers')
plt.ylabel('list with lag=1')
plt.title('Scatter plot of good rnd nos(lag=1)')
plt.show()

mean_grn = np.mean(good_rn)
std_grn = np.std(good_rn)

plt.hist(good_rn,bins=25,edgecolor='black',label=f"$\mu$:{mean_grn:.2f}, $\sigma$:{std_grn:.2f}")
plt.legend()
plt.title('Random numbers with uniform deviate')
plt.ylabel('counts')
plt.show()
'''
good_r = [(i - mean_grn) for i in good_rn]
result = np.correlate(good_r,good_r,mode='full')
sum_cor = sum(result)/len(result)
print('corr: ',sum_cor)
'''
k_lag = []
N = len(good_rn)
mean_sq = np.mean(good_rn)**2
variance = np.var(good_rn)

# c = (<x_nx_n+k> - <mean>**2)/var
for k in range(N):
    y=0
    for i in range(N-k):
        x = good_rn[i]*good_rn[i+k]
        y = y+x
    avg = y/(N-k)
    c = (avg - mean_sq)/variance
    k_lag.append(c)

plt.plot(range(N),k_lag,'.')
plt.title('Autocorrelation for good random numbers')
plt.xlabel('lag')
plt.ylabel('Autocorrelation')
plt.grid(True)
plt.show()

k_lag = []
N = len(bad_rn)
mean_sq = np.mean(bad_rn)**2
variance = np.var(bad_rn)

# c = (<x_nx_n+k> - <mean>**2)/var
for k in range(N):
    y=0
    for i in range(N-k):
        x = bad_rn[i]*bad_rn[i+k]
        y = y+x
    avg = y/(N-k)
    c = (avg - mean_sq)/variance
    k_lag.append(c)

plt.plot(range(N),k_lag,'.')
plt.title('Autocorrelation for bad random numbers')
plt.xlabel('lag')
plt.ylabel('Autocorrelation')
plt.grid(True)
plt.show()

