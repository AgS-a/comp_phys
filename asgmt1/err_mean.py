import matplotlib.pyplot as plt
import numpy as np

diff = [0.045711,0.000447,0.000060]
samples = [100,10000,1000000]

diff_ln = [np.log10(i) for i in diff]
samples_ln = [np.log10(i) for i in samples]

slope, _ = np.polyfit(samples_ln,diff_ln,1)
print("slope: ",slope)

plt.grid(True)
plt.title('log-log plot of no.of samples and error')
plt.xlabel('log sample size')
plt.ylabel('log error')
plt.plot(samples_ln,diff_ln,'.')
plt.show()
