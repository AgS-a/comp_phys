import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('buffon.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8]
num_log = [np.log10(i) for i in num]
diff_log = [np.log10(i) for i in diff]

slope, intercept = np.polyfit(num_log,diff_log,1)
fit_x = np.linspace(min(num),max(num),1000)
fit_y = [(i**slope)*(10**intercept) for i in fit_x]

plt.loglog(num,diff,'.')
plt.loglog(fit_x,fit_y,label=f'slope: {slope:.3f}')
plt.xlabel('throws')
plt.ylabel('error')
plt.legend()
plt.title('log-log plot of n_throw vs error')
plt.grid(True,which="both",linestyle='--')
plt.show()
