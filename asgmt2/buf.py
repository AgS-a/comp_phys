import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('buffon.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1,2,3,4,5,6,7,8]
diff_log = [np.log10(i) for i in diff]

slope, _ = np.polyfit(num,diff_log,1)
print(slope)

plt.plot(num,diff_log,'.',label='slope_from_fit:-0.469')
plt.xlabel('log throws')
plt.ylabel('log error')
plt.legend()
plt.title('log-log plot of n_throw vs error')
plt.grid(True)
plt.show()
