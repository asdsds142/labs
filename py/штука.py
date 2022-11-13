import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
from mpl_toolkits.mplot3d import Axes3D

u, v = np.mgrid[0:6*np.pi:70j, 0:2*np.pi:30j]
x = 8*u-8*np.sin(u)
y = 8*u-8*np.cos(u)
z = x*0

fig = plt.figure(figsize=(10, 10))
ax = fig.add_subplot(111, projection='3d')
ax.plot_wireframe(x, y, z)
ax.legend()

x = (3.14+np.cos(u))*np.cos(v)
y = (3.14+np.cos(u))*np.sin(v)
z = np.sin(u)

fig2 = plt.figure(figsize=(10, 10))
ax2 = fig2.add_subplot(111, projection='3d')
ax2.plot_wireframe(x, y, z)
ax2.legend()

plt.show()

