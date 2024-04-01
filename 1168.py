# ॥ श्री गणेशाय नमः ॥
import math
import matplotlib.pyplot as plt
import numpy as np

# Create a figure and axis
fig, ax = plt.subplots(figsize=(6, 6), subplot_kw=dict(polar=True))

# Draw the circle and radial lines
theta = np.linspace(0, 2 * np.pi, 360)
radii = np.ones(360)
ax.plot(theta, radii, 'k-', lw=0.5)
ax.set_rmax(1.1)
ax.set_rticks([])

# Label the angles
angles = np.linspace(0, 2 * np.pi, 24, endpoint=False)
labels = [f"{int(np.rad2deg(angle))}°" for angle in angles]
ax.set_xticks(angles)
ax.set_xticklabels(labels)

# Draw the red circle
ax.plot(theta, [0.5] * 360, 'r-', lw=2)

# Draw the green curve
theta_curve = np.linspace(0, 2 * np.pi, 100)
radii_curve = [np.cos((theta - 3 * np.pi / 180) / 5) for theta in theta_curve]
ax.plot(theta_curve, radii_curve, 'g-', lw=2)

# Draw the ticks on the green curve
theta_ticks = np.linspace(0, 2 * np.pi, 12)
for theta in theta_ticks:
    radii = np.cos((theta - 3 * np.pi / 180) / 5)
    ax.plot([theta, theta], [radii, radii + 0.03], 'g-', lw=2)

# Add the equations
ax.text(0.7, 0.3, r'$\theta = \cos\left(-\frac{3}{5}\right)$',
        transform=ax.transAxes, ha='left', va='center')
ax.text(-0.7, -0.3,
        r'$\theta = 2\pi - \cos\left(-\frac{3}{5}\right)$', transform=ax.transAxes, ha='right', va='center')

plt.show()


# ॥ जय श्री राम जय श्री कृष्ण ॥
