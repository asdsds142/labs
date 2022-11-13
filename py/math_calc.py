import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

plt1 = plt.subplot(231)
x = np.arange(0, 10, 0.001) # общий вид
y = 2.7**(0.22*x)*(0.88*np.cos(53.74*x) - 0.014*np.sin(53.74*x))-(0.00355*x+0.00000495)*np.cos(x)+(0.00000492*x-0.00000983)*np.sin(x) + 0.01288
plt1.xaxis.set_major_locator(ticker.MultipleLocator(1))
plt1.yaxis.set_major_locator(ticker.MultipleLocator(1))
plt1.yaxis.set_minor_locator(ticker.MultipleLocator(0.5))
plt1.grid(alpha = 1)
plt1.plot(x, x*0+4.87)
plt1.plot(x, x*0-4.87)
plt1.plot(x, y)


ax = plt.subplot(233)
x = np.arange(7.6, 8, 0.001) # более детальное изображение
y = 2.7**(0.22*x)*(0.88*np.cos(53.74*x) - 0.014*np.sin(53.74*x))-(0.00355*x+0.00000495)*np.cos(x)+(0.00000492*x-0.00000983)*np.sin(x) + 0.01288

ax.xaxis.set_major_locator(ticker.MultipleLocator(0.1))
ax.yaxis.set_major_locator(ticker.MultipleLocator(0.5))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(0.5))
ax.grid(alpha = 1)
ax.plot(x, x*0+4.87)
ax.plot(x, x*0-4.87)
ax.plot(x, y)
plt.show()


