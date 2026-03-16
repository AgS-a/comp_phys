import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

q3 = []
with open("q3.dat","r") as q3_dat:
    for lines in q3_dat:
        q3.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q3,'-')
ax1.set_title('Magnetization at each iteration(KbT=4.9,L=30)')
ax1.set_ylabel('Magnetization')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q3)
ax2.hist(q3, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q3), max(q3), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q4 = []
with open("q4.dat","r") as q4_dat:
    for lines in q4_dat:
        q4.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q4,'-')
ax1.set_title('Energy at each iteration(KbT=3.9,L=30)')
ax1.set_ylabel('Energy per spin')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q4)
ax2.hist(q4, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q4), max(q4), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q5_mag = []
with open("q5_mag.dat","r") as q5_mag_dat:
    for lines in q5_mag_dat:
        q5_mag.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q5_mag,'-')
ax1.set_title('Magnetization at each iteration(KbT=4.05,L=30)')
ax1.set_ylabel('Magnetization')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q5_mag)
ax2.hist(q5_mag, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q5_mag), max(q5_mag), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q5_E = []
with open("q5_E.dat","r") as q5_E_dat:
    for lines in q5_E_dat:
        q5_E.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q5_E,'-')
ax1.set_title('Energy at each iteration(KbT=4.05,L=30)')
ax1.set_ylabel('Energy per spin')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q5_E)
ax2.hist(q5_E, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q5_E), max(q5_E), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_mag_24 = []
with open("q6_mag_24.dat", "r") as q6_mag_24_dat:
    for lines in q6_mag_24_dat:
        q6_mag_24.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_mag_24, '-')
ax1.set_title('Magnetization at each iteration(KbT=3.9,L=24)')
ax1.set_ylabel('Magnetization')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_mag_24)
ax2.hist(q6_mag_24, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_mag_24), max(q6_mag_24), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_E_24 = []
with open("q6_E_24.dat", "r") as q6_E_24_dat:
    for lines in q6_E_24_dat:
        q6_E_24.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_E_24, '-')
ax1.set_title('Energy at each iteration(KbT=3.9,L=24)')
ax1.set_ylabel('Energy per spin')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_E_24)
ax2.hist(q6_E_24, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_E_24), max(q6_E_24), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_mag_30 = []
with open("q6_mag_30.dat", "r") as q6_mag_30_dat:
    for lines in q6_mag_30_dat:
        q6_mag_30.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_mag_30, '-')
ax1.set_title('Magnetization at each iteration(KbT=3.9,L=30)')
ax1.set_ylabel('Magnetization')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_mag_30)
ax2.hist(q6_mag_30, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_mag_30), max(q6_mag_30), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_E_30 = []
with open("q6_E_30.dat", "r") as q6_E_30_dat:
    for lines in q6_E_30_dat:
        q6_E_30.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_E_30, '-')
ax1.set_title('Energy at each iteration(KbT=3.9,L=30)')
ax1.set_ylabel('Energy per spin')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_E_30)
ax2.hist(q6_E_30, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_E_30), max(q6_E_30), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_mag_36 = []
with open("q6_mag_36.dat", "r") as q6_mag_36_dat:
    for lines in q6_mag_36_dat:
        q6_mag_36.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_mag_36, '-')
ax1.set_ylabel('Magnetization')
ax1.set_title('Magnetization at each iteration(KbT=3.9,L=36)')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_mag_36)
ax2.hist(q6_mag_36, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_mag_36), max(q6_mag_36), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()


q6_E_36 = []
with open("q6_E_36.dat", "r") as q6_E_36_dat:
    for lines in q6_E_36_dat:
        q6_E_36.append(float(lines.strip()))

fig, (ax1, ax2) = plt.subplots(1, 2, sharey=True, gridspec_kw={'width_ratios': [4, 1]})
ax1.plot(q6_E_36, '-')
ax1.set_title('Energy at each iteration(KbT=3.9,L=36)')
ax1.set_ylabel('Energy per spin')
ax1.set_xlabel("Iteration")
mu, std = norm.fit(q6_E_36)
ax2.hist(q6_E_36, bins=50, density=True, orientation='horizontal', alpha=0.6)
y = np.linspace(min(q6_E_36), max(q6_E_36), 100)
ax2.plot(norm.pdf(y, mu, std), y, 'k-')
ax2.set_title(f"Mean: {mu:.3f}\nStd: {std:.3f}", fontsize=10)
plt.show()
