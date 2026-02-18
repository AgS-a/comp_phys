import matplotlib.pyplot as plt

for i in range(5):
    M=[]
    num = (i+3) * 10
    name = "L_mag_%0.0f.dat" %num
    with open(name,"r") as data:
        for lines in data:
            M.append(float(lines.strip()))
    plt.plot(M,'-')
    plt.ylabel('Magnetization')
    plt.title(f'Magnetization at each iteration(L={num},L=3.7)')
    plt.show()
