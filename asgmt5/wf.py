import numpy as np
import matplotlib.pyplot as plt

def plot_wavefunction(filename, a, num_G_points, k_index, band_index):

    with open(filename, "r") as f:
        lines = f.readlines()

    # Group the file data into blocks based on blank lines
    blocks = []
    current_block = []
    for line in lines:
        if line.strip() == "":
            if current_block:
                blocks.append(current_block)
                current_block = []
        else:
            current_block.append(line.strip())
    if current_block:
        blocks.append(current_block)

    target_block = blocks[k_index]
    k_val = float(target_block[0])

    # Extract data for the requested band (index + 1 skips the k_val row)
    band_data = target_block[band_index + 1].split()
    energy = float(band_data[0])
    
    # The rest of the line contains the eigenvector coefficients
    eigenvector = np.array([float(val) for val in band_data[1:]])

    x = np.linspace(-2*a, 2*a, 1000)
    #x = np.linspace(-a,a,1000)
    psi = np.zeros_like(x, dtype=complex)

    m_edge_pt = -(num_G_points - 1) // 2
    G_pts = [(2 * np.pi * m_edge_pt / a) + (i * 2 * np.pi / a) for i in range(num_G_points)]

    # Sum the plane waves
    for i in range(num_G_points):
        psi += eigenvector[i] * np.exp(1j * (k_val + G_pts[i]) * x)

    prob_density = np.abs(psi)**2

    plt.figure(figsize=(8, 4))
    plt.plot(x, prob_density, color='purple', linewidth=2)
    
    plt.axvline(x=-a/2, color='black', linestyle='--', alpha=0.5)
    plt.axvline(x=a/2, color='black', linestyle='--', alpha=0.5)
    
    plt.xlabel('x')
    plt.ylabel(r'$|\psi(x)|^2$')
    plt.title(f' k={k_val:.3f}, Band={band_index+1}, E={energy:.3f}')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

plot_wavefunction(
    filename="ev_a1.50_Vo0.50_nk401_ng3.dat", 
    a=1.50, 
    num_G_points=3, 
    k_index=0,      
    band_index=0    
)

plot_wavefunction(
    filename="ev_a1.50_Vo0.50_nk401_ng3.dat", 
    a=1.50, 
    num_G_points=3, 
    k_index=0,      
    band_index=1    
)

plot_wavefunction(
    filename="ev_a1.50_Vo0.50_nk401_ng3.dat", 
    a=1.50, 
    num_G_points=3, 
    k_index=200,      
    band_index=0    
)

plot_wavefunction(
    filename="ev_a1.50_Vo10.00_nk401_ng21.dat",
    a=1.50,
    num_G_points=21,
    k_index=200,
    band_index=0
)

plot_wavefunction(
    filename="ev_a1.50_Vo10.00_nk401_ng21.dat",
    a=1.50,
    num_G_points=21,
    k_index=0,
    band_index=10
)
dat_files = ['ev_a10.00_Vo0.50_nk401_ng21.dat',
'ev_a10.00_Vo8.50_nk401_ng21.dat',
'ev_a1.00_Vo0.00_nk401_ng11.dat',
'ev_a1.00_Vo0.00_nk401_ng21.dat',
'ev_a1.00_Vo0.00_nk401_ng3.dat',
'ev_a1.00_Vo0.00_nk401_ng61.dat',
'ev_a1.00_Vo0.50_nk401_ng21.dat',
'ev_a1.00_Vo8.50_nk401_ng21.dat',
'ev_a1.50_Vo0.00_nk401_ng11.dat',
'ev_a1.50_Vo0.00_nk401_ng21.dat',
'ev_a1.50_Vo0.00_nk401_ng3.dat',
'ev_a1.50_Vo0.00_nk401_ng61.dat',
'ev_a1.50_Vo0.50_nk401_ng11.dat',
'ev_a1.50_Vo0.50_nk401_ng21.dat',
'ev_a1.50_Vo0.50_nk401_ng3.dat',
'ev_a1.50_Vo0.50_nk401_ng61.dat',
'ev_a1.50_Vo10.00_nk401_ng21.dat',
'ev_a1.50_Vo2.00_nk401_ng21.dat',
'ev_a1.50_Vo4.00_nk401_ng21.dat',
'ev_a1.50_Vo6.00_nk401_ng21.dat',
'ev_a1.50_Vo8.00_nk401_ng21.dat',
'ev_a1.50_Vo8.50_nk401_ng21.dat',
'ev_a2.50_Vo0.00_nk401_ng11.dat',
'ev_a2.50_Vo0.00_nk401_ng21.dat',
'ev_a2.50_Vo0.00_nk401_ng3.dat',
'ev_a2.50_Vo0.00_nk401_ng61.dat',
'ev_a4.00_Vo0.50_nk401_ng21.dat',
'ev_a4.00_Vo8.50_nk401_ng21.dat',
'ev_a7.00_Vo0.50_nk401_ng21.dat',
'ev_a7.00_Vo8.50_nk401_ng21.dat',]

