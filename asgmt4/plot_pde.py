import matplotlib.pyplot as plt
import numpy as np

data1 = np.loadtxt("pde1.dat")
data1 = np.transpose(data1)
print(data1[19][19])

plt.imshow(data1,cmap="plasma")
plt.colorbar(label='Temperature')
ax = plt.gca() # Get the current axes
ax.xaxis.tick_top() # Move the ticks and numbers to the top
ax.xaxis.set_label_position('top') # Move the "x" label to the top
plt.xlabel("x")
plt.ylabel("y")
plt.title("Temperature profile of 2-d plate with given boundary conditions")
plt.show()

data2 = np.loadtxt("pde2.dat")
#data2 = np.transpose(data2)
print(data2[9][9])

plt.imshow(data2,cmap="plasma")
plt.colorbar(label="Temperature")
plt.xlabel("x")
plt.ylabel("y")
plt.title("Temperature profile of 2-d plate with given Neumann boundary conditions")
plt.show()
