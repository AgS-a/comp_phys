import matplotlib.pyplot as plt

sum_of_ran_nos = []

with open('dist_sum_10k.dat','r') as fil:
    for line in fil:
        sum_of_ran_nos.append(line.strip())

plt.hist(sum_of_ran_nos)
plt.show()
