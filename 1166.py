import numpy as np
import matplotlib.pyplot as plt

# Parameters
num_samples = 1000  # Number of samples
num_steps = 1000  # Number of steps
dt = 1.0 / num_steps  # Time step

# Generate Wiener process increments
increments = np.random.normal(0, np.sqrt(dt), (num_samples, num_steps))

# Generate Wiener process path
wiener_process = np.cumsum(increments, axis=1)

# Plotting
plt.plot(np.arange(0, 1, dt), wiener_process.T)
plt.title("Wiener Process (Brownian Motion)")
plt.xlabel("Time")
plt.ylabel("Value")
plt.grid(True)
plt.show()
