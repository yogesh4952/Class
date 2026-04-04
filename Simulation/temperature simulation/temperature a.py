import numpy as np
import matplotlib.pyplot as plt

# Parameters
length = 1.0  # Length of the rod (meters)
num_points = 100  # Number of discrete points
dx = length / (num_points - 1)  # Spatial step size
dt = 0.01  # Time step size (seconds)
total_time = 10.0  # Total simulation time (seconds)
thermal_diffusivity = 1.17e-5  # Thermal diffusivity of steel (m^2/s)
initial_temp = 20.0  # Initial temperature of the rod (°C)
heat_source_temp = 100.0  # Temperature of the heat source (°C)

# Initialize temperature array
temperature = np.full(num_points, initial_temp)

# Store temperature data for visualization
time_steps = int(total_time / dt)
temperature_history = np.zeros((time_steps, num_points))

# Simulation loop
for t in range(time_steps):
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

    # Store temperature data for visualization
    temperature_history[t, :] = temperature

# Visualization
plt.figure(figsize=(10, 6))

# Heatmap of temperature distribution over time
plt.imshow(temperature_history, aspect='auto', cmap='hot', origin='lower',
           extent=[0, length, 0, total_time], vmin=initial_temp, vmax=heat_source_temp)
plt.colorbar(label='Temperature (°C)')
plt.xlabel('Position along the rod (m)')
plt.ylabel('Time (s)')
plt.title('Heat Distribution in a Metal Rod Over Time')

# Plot temperature profiles at specific times
selected_times = [0, int(time_steps / 4), int(time_steps / 2), time_steps - 1]
for t in selected_times:
    plt.plot(np.linspace(0, length, num_points), temperature_history[t, :],
             label=f'Time = {t * dt:.2f} s')

plt.legend()
plt.show()