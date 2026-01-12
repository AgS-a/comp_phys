import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

random_nos = []

with open('random.dat','r') as fil:
    for line in fil:
        random_nos.append(float(line.strip()))

plt.hist(random_nos,bins=10,edgecolor='black')
plt.show()

x = np.correlate(random_nos,random_nos,mode='full')
print(x)
