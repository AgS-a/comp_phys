import matplotlib.pyplot as plt
import numpy as np

diff = []

with open('pi_diff.dat','r') as pid:
    for lines in pid:
        diff.append(float(lines.strip()))

num = [1,2,3,4,5,6,7,8,9]
diff_log = [np.log10(i) for i in diff]

plt.plot(num,diff_log,'.')
plt.show()
