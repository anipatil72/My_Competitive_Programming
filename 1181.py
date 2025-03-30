import random


def monte_carlo_pi(num_samples=10000):
    inside_circle = 0

    for _ in range(num_samples):
        x, y = random.uniform(0, 1), random.uniform(
            0, 1)  # Random point in unit square
        if x**2 + y**2 <= 1:  # Check if point is inside quarter-circle
            inside_circle += 1

    pi_estimate = (inside_circle / num_samples) * 4  # Scale to full circle
    return pi_estimate


# Run the simulation
num_samples = 1000  # Increase for better accuracy
estimated_pi = monte_carlo_pi(num_samples)
print(f"Estimated value of Pi with {num_samples} samples: {estimated_pi}")
