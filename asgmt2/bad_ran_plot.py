import matplotlib.pyplot as plt
#import pandas as pd
import numpy as np

bad_rn = []
with open("bad_random_numbers.dat","r") as brn:
    for lines in brn:
        bad_rn.append(float(lines.strip()))

bad_rn_y = bad_rn[1:]
bad_rn_y.append(bad_rn[0])
plt.plot(bad_rn,bad_rn_y,'.')
plt.title('Bad rnd no generator(lag=1)')
#plt.hist(bad_rn,bins=25,edgecolor='black')
plt.show()

good_rn = []
with open("random.dat","r") as grn:
    for lines in grn:
        good_rn.append(float(lines.strip()))

#good_rn = pd.DataFrame(good_rn)
#pd.plotting.lag_plot(good_rn,lag=1)
good_rn_y = good_rn[1:]
good_rn_y.append(good_rn[0])
plt.plot(good_rn,good_rn_y,'.')

plt.title('Scatter plot with lag1')
plt.show()
plt.hist(good_rn,bins=25,edgecolor='black')
plt.title('Random numbers with uniform deviate')
plt.show()

print('Mean: ',np.mean(good_rn))
print('std_dev: ',np.std(good_rn))
good_r = [(i - np.mean(good_rn)) for i in good_rn]
result = np.correlate(good_r,good_r,mode='full')
cor = result[result.size // 2:] / (np.var(good_r) * len(good_r))
print('corr: ',cor)
