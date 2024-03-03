import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Set up figure, axis, and plot element
fig, ax = plt.subplots()
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
points, = ax.plot([], [], 'bo')  # 'bo' means blue color and circle markers

# Initialization function: plot the background of each frame
def init():
    points.set_data([], [])
    return points,

# Animation function, this is called sequentially
def animate(i):
    x = np.random.uniform(0, 10, 10)  # Generate 10 random x-coordinates
    y = np.random.uniform(0, 10, 10)  # Generate 10 random y-coordinates
    points.set_data(x, y)
    return points,

# Create animation
ani = animation.FuncAnimation(fig, animate, init_func=init, frames=200, interval=100, blit=True)

plt.show()
