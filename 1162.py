import numpy as np
import matplotlib.pyplot as plt

# Parameters
num_points = 1000
mean = 0  # Mean of the white noise process (zero for white noise)
std_dev = 1  # Standard deviation of the white noise process

# Generate white noise process
white_noise = np.random.normal(mean, std_dev, size=num_points)

# Plot white noise process
plt.plot(white_noise)
plt.title("White Noise Process")
plt.xlabel("Time")
plt.ylabel("Value")
plt.grid(True)
plt.show()
