import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('pi_diff.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9]
diff_log = [np.log10(i) for i in diff]
num_log = [np.log10(i) for i in num]

dif = diff_log[:5]
nu = num_log[:5]
slope_trial, intercept_trial = np.polyfit(nu,dif,1)
#print(slope_trial)

slope, intercept = np.polyfit(num_log,diff_log,1)
fit_x = np.linspace(10**min(nu),10**max(nu),1000)
fit_y = [(i**slope_trial)*(10**intercept_trial) for i in fit_x]

plt.loglog(fit_x,fit_y,label=f'slope: {slope_trial:.3f}')
plt.loglog(num,diff,'.')
plt.legend()
plt.title('log-log plot of grid_points vs error')
plt.xlabel('grid points')
plt.ylabel('error')
plt.grid(True,which="both",linestyle='--')
plt.show()
