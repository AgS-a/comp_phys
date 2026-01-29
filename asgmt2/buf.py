import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('buffon.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1,2,3,4,5,6,7,8]
diff_log = [np.log10(i) for i in diff]

plt.plot(num,diff_log,'.')
plt.title('log-log plot of n_throw vs error')
plt.grid(True)
plt.show()
