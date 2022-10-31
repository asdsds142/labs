import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

plt1 = plt.subplot(231)
x = np.arange(2, 4, 0.001)
y = 2.7**(0.9*x)*(0.195*np.cos(44*x) - 0.047*np.sin(44*x))+(0.000003*x-0.000006)*np.cos(x)+(0.005*x+0.000003)*np.sin(x) + 0.00533
plt1.xaxis.set_major_locator(ticker.MultipleLocator(1))
plt1.yaxis.set_major_locator(ticker.MultipleLocator(1))
plt1.yaxis.set_minor_locator(ticker.MultipleLocator(0.5))
plt1.grid(alpha = 1)
plt1.plot(x, x*0+4)
plt1.plot(x, x*0-4)
plt1.plot(x, y)


ax = plt.subplot(233)
x = np.arange(3.2, 3.55, 0.001)
y = 2.7**(0.9*x)*(0.195*np.cos(44*x) - 0.047*np.sin(44*x))+(0.000003*x-0.000006)*np.cos(x)+(0.005*x+0.000003)*np.sin(x) + 0.00533

ax.xaxis.set_major_locator(ticker.MultipleLocator(0.05))
ax.yaxis.set_major_locator(ticker.MultipleLocator(0.5))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(0.5))
ax.grid(alpha = 1)
ax.plot(x, x*0+4)
ax.plot(x, x*0-4)
ax.plot(x, y)
plt.show()


