import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('pi_diff.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1,2,3,4,5,6,7,8,9]
diff_log = [np.log10(i) for i in diff]

slope, _ = np.polyfit(num,diff_log,1)

plt.plot(num,diff_log,'.',label='slope_from_fit:-0.998')
print(slope)
plt.legend()
plt.title('log-log of grid_points vs error')
plt.show()
