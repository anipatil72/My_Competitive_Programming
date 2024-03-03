import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Set up the figure and axis
fig, ax = plt.subplots()
ax.set_xlim(0, 2*np.pi)
ax.set_ylim(-3, 3)

# Initialize the line object
line, = ax.plot([], [], lw=2)

# Initialization function: plot the background of each frame


def init():
    line.set_data([], [])
    return line,

# Animation function, called sequentially


def animate(i):
    t = np.linspace(0, 2*np.pi, 1000)
    A = np.random.normal(0, 1)  # Generate a standard normal random variable
    X = A * np.sin(2*t)
    line.set_data(t, X)
    return line,


# Create animation
ani = animation.FuncAnimation(fig, animate, frames=200, interval=50, blit=True)

plt.xlabel('Time (t)')
plt.ylabel('X(t)')
plt.title('Random Process: X(t) = A sin(2t), A ~ N(0, 1)')

plt.show()
