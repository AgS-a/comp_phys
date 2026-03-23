import matplotlib.pyplot as plt
import numpy as np

data1 = np.loadtxt("pde1.dat")
print(data1[19][19])

plt.imshow(data1,cmap="viridis")
plt.colorbar(label='Temperature')
plt.xlabel("y")
plt.ylabel("x")
plt.title("Temperature profile of 2-d plate with given boundary conditions")
plt.show()

data2 = np.loadtxt("pde2.dat")
print(data2[9][9])

plt.imshow(data2,cmap="viridis")
plt.colorbar(label="Temperature")
plt.xlabel("y")
plt.ylabel("x")
plt.title("Temperature profile of 2-d plate with given Neumann boundary conditions")
plt.show()
