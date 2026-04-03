import numpy as np

di = -0.5 + (0.5*((2*np.pi/1.5)**2))
matrix = np.array([[-0.5,-0.25,0],[-0.25,di,-0.25],[0,-0.25,di]])

eigenvals, _ = np.linalg.eig(matrix)

print(eigenvals)
