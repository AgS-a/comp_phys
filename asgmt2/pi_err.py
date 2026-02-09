import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('pi_diff.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9]
diff_log = [np.log10(i) for i in diff]
num_log = [np.log10(i) for i in num]



slope, intercept = np.polyfit(num_log,diff_log,1)
fit_x = np.linspace(min(num),max(num),1000)
fit_y = [(i**slope)*(10**intercept) for i in fit_x]

plt.loglog(fit_x,fit_y,label=f'slope: {slope:.2e}')
plt.loglog(num,diff,'.')
plt.legend()
plt.grid(True,which="both",linestyle='--')
plt.title('log-log of grid_points vs error')
plt.xlabel('log grid points')
plt.ylabel('log error')
plt.show()
