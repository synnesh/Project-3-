import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import sys

#Kjor med outfilnavn som kommandlinjeargument
nr_of_planets = 3

pos1 = np.loadtxt(sys.argv[1], usecols=(1,3,4,5))
earth = np.transpose(pos1[0::nr_of_planets,1:])
sun = np.transpose(pos1[1::nr_of_planets,1:])
jupiter = np.transpose(pos1[2::nr_of_planets,1:])


fig = plt.figure()

plt.plot(earth[0],earth[1])
plt.plot(sun[0],sun[1])
plt.plot(jupiter[0],jupiter[1])
plt.legend(["Earth","Sun", "Jupiter"])
plt.show()


"""
ax = fig.gca(projection='3d')


ax.plot(earth[0],earth[1],earth[2])
ax.plot(sun[0],sun[1],sun[2])
ax.plot(jupiter[0],jupiter[1],jupiter[2])

plt.legend(["Earth","Sun", "Jupiter"])
ax.set_xlabel("x[Au]")
ax.set_ylabel("y[Au]")
ax.set_zlabel("z[Au]")"""

plt.show()
