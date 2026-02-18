import matplotlib.pyplot as plt

for i in range(10):
    M = []
    num = 3.1 + (0.2*i)
    name = "temp_mag_%.6f.dat" %num 
    save_name = "T_%.2f.jpg" %num
    with open(name,"r") as data:
        for lines in data:
            M.append(float(lines.strip()))
    plt.plot(M,'-')
    plt.ylabel('Magnetization')
    plt.title(f'Magnetization at each iteration(KbT={num},L=30)')
    plt.savefig(save_name)
    plt.show()
