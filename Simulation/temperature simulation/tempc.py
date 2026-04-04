import numpy as np
import matplotlib.pyplot as plt

# Parameters
length = 1.0  # Length of the rod (meters)
num_points = 100  # Number of discrete points
dx = length / (num_points - 1)  # Spatial step size
dt = 0.1  # Time step size (seconds)
total_time = 1200.0  # Total simulation time (20 minutes = 1200 seconds)
thermal_diffusivity = 1.17e-5  # Thermal diffusivity of steel (m^2/s)
initial_temp = 20.0  # Initial temperature of the rod (°C)
heat_source_temp = 100.0  # Temperature of the heat source (°C)

# Initialize temperature array
temperature = np.full(num_points, initial_temp)

# Set up the plot
plt.ion()  # Interactive mode
fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlabel("Position along the rod (m)")
ax.set_ylabel("Temperature (°C)")
ax.set_title("Real-Time Temperature Distribution in a Metal Rod")

# Create a colormap for temperature
cmap = plt.get_cmap('hot')
norm = plt.Normalize(vmin=initial_temp, vmax=heat_source_temp)

# Plot the initial state of the rod
positions = np.linspace(0, length, num_points)
rod = ax.scatter(positions, np.zeros(num_points), c=temperature, cmap=cmap, norm=norm, s=100)
plt.colorbar(rod, label='Temperature (°C)')

# Simulation loop
start_time = 0
while start_time <= total_time:
    # Apply boundary conditions
    temperature[0] = heat_source_temp  # Heat source at the left end
    temperature[-1] = temperature[-2]  # Insulated boundary at the right end

    # Update temperature using the finite difference method
    new_temperature = temperature.copy()
    for i in range(1, num_points - 1):
        new_temperature[i] = temperature[i] + thermal_diffusivity * dt / dx**2 * (
            temperature[i + 1] - 2 * temperature[i] + temperature[i - 1]
        )
    temperature = new_temperature

    # Update the rod's color based on temperature
    rod.set_array(temperature)
    ax.set_title(f"Real-Time Temperature Distribution (Time = {start_time:.1f} s)")

    # Pause to visualize the changes
    plt.pause(0.01)

    # Increment time
    start_time += dt

plt.ioff()
plt.show()