import numpy as np
import matplotlib.pyplot as plt

def plot_bands(filename):

    data = np.loadtxt(filename)

    filename = filename[:-4]
    # Extract k-points (1st column) and Energy bands (all remaining columns)
    k_pts = data[:, 0]
    energies = data[:, 1:]
    num_bands = energies.shape[1]

    plt.figure(figsize=(8, 6))

    for i in range(num_bands):
        if(i<5):
            plt.plot(k_pts, energies[:, i], label=f'Band {i+1}')

    plt.xlabel('k')
    plt.ylabel('E')
    plt.title(f'E vs k: {filename}')
    plt.grid(True, linestyle='--', alpha=0.7)

    plt.tight_layout()
    name = "./results/" + filename + ".jpg"
    #plt.savefig(name)
    plt.show()

dat_files = ['a10.00_Vo0.50_nk401_ng21.dat',
'a10.00_Vo8.50_nk401_ng21.dat',
'a1.00_Vo0.00_nk401_ng11.dat',
'a1.00_Vo0.00_nk401_ng21.dat',
'a1.00_Vo0.00_nk401_ng3.dat',
'a1.00_Vo0.00_nk401_ng61.dat',
'a1.00_Vo0.50_nk401_ng21.dat',
'a1.00_Vo8.50_nk401_ng21.dat',
'a1.50_Vo0.00_nk401_ng11.dat',
'a1.50_Vo0.00_nk401_ng21.dat',
'a1.50_Vo0.00_nk401_ng3.dat',
'a1.50_Vo0.00_nk401_ng61.dat',
'a1.50_Vo0.50_nk401_ng11.dat',
'a1.50_Vo0.50_nk401_ng21.dat',
'a1.50_Vo0.50_nk401_ng3.dat',
'a1.50_Vo0.50_nk401_ng61.dat',
'a1.50_Vo10.00_nk401_ng21.dat',
'a1.50_Vo2.00_nk401_ng21.dat',
'a1.50_Vo4.00_nk401_ng21.dat',
'a1.50_Vo6.00_nk401_ng21.dat',
'a1.50_Vo8.00_nk401_ng21.dat',
'a1.50_Vo8.50_nk401_ng21.dat',
'a2.50_Vo0.00_nk401_ng11.dat',
'a2.50_Vo0.00_nk401_ng21.dat',
'a2.50_Vo0.00_nk401_ng3.dat',
'a2.50_Vo0.00_nk401_ng61.dat',
'a4.00_Vo0.50_nk401_ng21.dat',
'a4.00_Vo8.50_nk401_ng21.dat',
'a7.00_Vo0.50_nk401_ng21.dat',
'a7.00_Vo8.50_nk401_ng21.dat']

for i in dat_files:
    plot_bands(i)
