import matplotlib.pyplot as plt

for i in range(3):
    M = []
    num = 3.9 + (0.2*i)
    if i==2:
        num = 4.2
    name = "temp_magne_%.6f.dat" %num 
    save_name = "Temp_%.2f.jpg" %num
    with open(name,"r") as data:
        for lines in data:
            M.append(float(lines.strip()))
    plt.plot(M,'-')
    plt.ylabel('Magnetization')
    plt.title(f'Magnetization at each iteration(KbT={num},L=50)')
    plt.savefig(save_name)
    plt.show()

