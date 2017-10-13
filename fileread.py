import numpy as np
import sys
import matplotlib.pyplot as plt

filename = sys.argv[1]

infile = open(filename, "r")


line1 = infile.readline().split()

N = int(line1[0])
t_max = int(line1[1])

print N, t_max
infile.readline()

vx = np.zeros(N)
vy=np.zeros(N)
x=np.zeros(N)
y=np.zeros(N)
time = np.zeros(N)

linenr = 0

for lines in infile:
    values = lines.split()
    time[linenr] = float(values[0])
    x[linenr] = float(values[1])
    y[linenr] = float(values[2])
    vx[linenr] = float(values[3])
    vy[linenr] = float(values[4])
    linenr+=1

infile.close()
plt.figure(1);
plt.plot(x,y)
plt.grid()
plt.title("Euler method, N = %d , number of years: %d" %(N,t_max))
plt.xlabel("x [Au]")
plt.ylabel("y [Au]")
plt.axis('equal');
plt.show()
