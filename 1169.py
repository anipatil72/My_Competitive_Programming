import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Create a new figure and axis
fig, ax = plt.subplots(figsize=(8, 6))

# Define node positions
node_positions = {
    'start': (0, 3),
    'est': (3, 3),
    'update': (3, 1),
    'stress': (3, -1),
    'arrest': (3, -3),
    'length': (3, -5)
}

# Define node properties
node_props = {
    'facecolor': 'white',
    'edgecolor': 'black',
    'boxstyle': 'square,pad=0.3',
    'linewidth': 1.5
}

# Add nodes
start_text = ax.annotate('CRACK\nINITIATION\nCRITERIA',
                         xy=node_positions['start'], bbox=node_props)
est_text = ax.annotate('ESTIMATED\nCRACK LENGTH ($L_c$)',
                       xy=node_positions['est'], bbox=node_props)
update_text = ax.annotate('UPDATE UPLIFT\nPRESSURE ACCORDING\nTO CRACK LENGTH AND\nDRAINAGE',
                          xy=node_positions['update'], bbox=node_props)
stress_text = ax.annotate(
    'STRESS\nCOMPUTATION ($\sigma_f$)', xy=node_positions['stress'], bbox=node_props)
arrest_text = ax.annotate('CRACK ARREST\n(PROPAGATION) CRITERION',
                          xy=node_positions['arrest'], ha='center', va='center', bbox=node_props)
length_text = ax.annotate('CRACK LENGTH\nIS DETERMINED',
                          xy=node_positions['length'], bbox=node_props)

# Add arrows
ax.annotate('', xy=node_positions['est'], xytext=node_positions['start'], arrowprops=dict(
    arrowstyle='<-', linewidth=1.5))
ax.annotate('', xy=node_positions['update'], xytext=node_positions['est'], arrowprops=dict(
    arrowstyle='->', linewidth=1.5))  # Simplify arrow style here
ax.annotate('', xy=node_positions['stress'], xytext=node_positions['update'], arrowprops=dict(
    arrowstyle='->', linewidth=1.5))  # Simplify arrow style here
ax.annotate('', xy=node_positions['arrest'], xytext=node_positions['stress'], arrowprops=dict(
    arrowstyle='->', linewidth=1.5))  # Simplify arrow style here
ax.annotate('', xy=node_positions['length'], xytext=node_positions['arrest'], arrowprops=dict(
    arrowstyle='->', linewidth=1.5))  # Simplify arrow style here
ax.annotate('', xy=node_positions['stress'], xytext=(node_positions['stress'][0]-2,
            node_positions['stress'][1]), arrowprops=dict(arrowstyle='->', linewidth=1.5))  # Simplify arrow style here

# Add annotation for crack length
ax.annotate('', xy=(6, -1), xytext=(4, -1),
            arrowprops=dict(arrowstyle='<->', linewidth=1.5))
ax.text(5, -1, '$L_c$', ha='center', va='center')
ax.add_patch(patches.Rectangle((4.2, -1.1), 0.6, 0.2, facecolor='red'))
ax.add_patch(patches.Rectangle((4, -1.5), 0.2, 0.4, facecolor='blue'))

# Remove axes and set aspect ratio
ax.set_axis_off()
ax.set_aspect('equal')

# Adjust plot limits
plt.xlim(-1, 7)
plt.ylim(-6, 4)

# Show the plot
plt.show()
