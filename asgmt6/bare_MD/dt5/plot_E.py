import matplotlib.pyplot as plt
import numpy as np

KE = []
with open("KE.dat","r") as ke_dat:
    for lines in ke_dat:
        KE.append(float(lines.strip()))

PE = []
with open("PE.dat","r") as pe_dat:
    for lines in pe_dat:
        PE.append(float(lines.strip()))

TE =[]

for i in range(len(PE)):
    TE.append(KE[i] + PE[i])

plt.plot(KE,'.',label="KE")
plt.plot(PE,'.',label="PE")
plt.plot(TE,'.',label="TE")

plt.xlabel("Time(50 iterations)")
plt.ylabel("Energy(KbT)")
plt.title("Time evolution of energies")

plt.legend()
plt.grid(True)
plt.show()


mean_te = np.mean(TE)
sigma_te = np.std(TE)

# Create a figure with two subplots side-by-side
# gridspec_kw sets the width ratio (e.g., 3 parts for the plot, 1 part for the histogram)
# sharey=True locks the Y-axis so they scale together
fig, (ax_main, ax_hist) = plt.subplots(1, 2, figsize=(10, 5),
                                       gridspec_kw={'width_ratios': [3, 1]},
                                       sharey=True)

# --- Main Plot (Time Series) ---
ax_main.plot(TE, '.', label="dt=0.005")

ax_main.axhline(mean_te, color='black', linestyle='dashed', alpha=0.7, label="Mean")

ax_main.grid(True)
ax_main.legend()
ax_main.set_xlabel("Time(50 iterations)")
ax_main.set_ylabel("Total Energy(KbT)")
ax_main.set_title("Fluctuation in Total energy")

# --- Side Plot (Distribution) ---
# orientation='horizontal' aligns the histogram bins with the main plot's Y-axis
ax_hist.hist(TE, bins=40, orientation='horizontal', color='skyblue', edgecolor='black')

ax_hist.axhline(mean_te, color='black', linestyle='dashed', alpha=0.7)

# Display Mean and Sigma as text on the histogram
stats_text = f"Mean: {mean_te:.3e}\nSigma: {sigma_te:.3e}"
ax_hist.text(0.5, 0.95, stats_text,
             transform=ax_hist.transAxes,
             verticalalignment='top',
             horizontalalignment='center',
             bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

ax_hist.set_xlabel("Frequency")
ax_hist.set_title("TE Distribution")

# Adjust layout to prevent overlap
plt.tight_layout()
plt.show()
