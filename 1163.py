import random
import matplotlib.pyplot as plt


def estimate_pi(num_samples):
    inside_circle = 0
    circle_x = []
    circle_y = []
    square_x = [-1, 1, 1, -1, -1]
    square_y = [-1, -1, 1, 1, -1]

    for _ in range(num_samples):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        distance = x**2 + y**2

        if distance <= 1:
            inside_circle += 1
            circle_x.append(x)
            circle_y.append(y)

    pi_estimate = (inside_circle / num_samples) * 4
    return pi_estimate, circle_x, circle_y, square_x, square_y


# Number of samples for the simulation
num_samples = 1000

# Perform the Monte Carlo simulation
pi_estimate, circle_x, circle_y, square_x, square_y = estimate_pi(num_samples)

# Plot the results
plt.figure(figsize=(8, 8))
plt.plot(square_x, square_y, 'b-')  # Plot the square
# Plot the points inside the circle
plt.plot(circle_x, circle_y, 'ro', markersize=2)
plt.axis('equal')
plt.title(
    f'Monte Carlo Simulation for $\pi$ Estimation (N={num_samples})\nEstimated $\pi$ ≈ {pi_estimate:.5f}')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.show()
