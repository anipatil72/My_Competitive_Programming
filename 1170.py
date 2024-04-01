
# ॥ श्री गणेशाय नमः ॥
import math
import numpy as np
import matplotlib.pyplot as plt


# Parameters
L = 1.0  # Length of the rod
T = 0.5  # Total time
alpha = 0.01  # Thermal diffusivity
N = 100  # Number of spatial grid points
M = 500  # Number of time steps
dx = L / (N - 1)
dt = T / M

# Initial condition
u = np.zeros(N)
# Initial condition: A pulse in the middle
u[int(0.4 / dx):int(0.6 / dx)] = 1.0

# Finite difference method
for n in range(M):
    un = u.copy()
    for i in range(1, N - 1):
        u[i] = un[i] + alpha * dt / dx**2 * (un[i + 1] - 2 * un[i] + un[i - 1])

# Plotting
x = np.linspace(0, L, N)
plt.plot(x, u)
plt.xlabel('Position')
plt.ylabel('Temperature')
plt.title('Temperature distribution at t = {}'.format(T))
plt.grid(True)
plt.show()

# ॥ जय श्री राम जय श्री कृष्ण ॥
