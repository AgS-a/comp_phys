import matplotlib.pyplot as plt
import numpy as np

testlist = []
with open("a1.00_Vo0.00_nk401_ng3.dat","r") as test1dat:
    for lines in test1dat:
        testlist.append(lines.strip())

testsplit = [i.split('    ') for i in testlist]
k_pts = [float(i) for i in testsplit[j][0]
print(testsplit[-1][0])
