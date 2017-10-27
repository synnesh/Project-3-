import numpy as np
import sys
import matplotlib.pyplot as plt

filename = sys.argv[1]

infile = open(filename, "r")


line1 = infile.readline().split()

N = int(line1[0])
t_max = int(line1[1])
v0 = float(line1[2])

print N, t_max
infile.readline()

vx = np.zeros(N)
vy=np.zeros(N)
x=np.zeros(N)
y=np.zeros(N)
time = np.zeros(N)
r = np.zeros(N)

linenr = 0

for lines in infile:
    #if(linenr%100000):print linenr
    values = lines.split()
    time[linenr] = float(values[0])
    x[linenr] = float(values[1])
    y[linenr] = float(values[2])
    r[linenr] = float(values[5])
    linenr+=1

perihelionindex=[]
for i in xrange(1, N-1):
    if(r[i-1]>r[i] and r[i+1]>r[i]):
        perihelionindex.append(i)
        print i

print perihelionindex
lastperi=perihelionindex[-1]

tan = x[i]/y[i]

print tan
print tan/len(perihelionindex)

infile.close()
plt.axis('equal')
plt.plot(x,y)
plt.grid()
#plt.title("Verlet method, N = %d , Initial velocity: %.2f" %(N,v0))
plt.xlabel("x [Au]")
plt.ylabel("y [Au]")
plt.show()
