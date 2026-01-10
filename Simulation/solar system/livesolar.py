import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from astropy.time import Time
from astropy.coordinates import get_body_barycentric

# Define the names of the planets
PLANETS = ['mercury', 'venus', 'earth', 'mars', 'jupiter', 'saturn', 'uranus', 'neptune']

def get_planet_positions(time):
    """
    Calculate the positions of planets for a given time.
    :param time: Astropy Time object
    :return: Dictionary with planet names as keys and their (x, y) positions as values.
    """
    positions = {}
    for planet in PLANETS:
        pos = get_body_barycentric(planet, time)
        positions[planet] = (pos.x.value, pos.y.value)
    return positions

def animate(i, start_time, ax, scatters, labels, time_step_days=1):
    """
    Update function for the animation.
    :param i: Frame index
    :param start_time: Initial Astropy Time object
    :param ax: Matplotlib Axes object
    :param scatters: List of scatter plot objects for planets
    :param labels: List of text objects for planet labels
    :param time_step_days: Number of days to advance per frame
    """
    # Advance time by `time_step_days` for each frame
    current_time = start_time + i * time_step_days
    positions = get_planet_positions(current_time)

    # Update the positions of the planets
    for idx, planet in enumerate(PLANETS):
        x, y = positions[planet]
        scatters[idx].set_offsets([x, y])  # Update scatter position
        labels[idx].set_position((x, y))  # Update label position

    # Update the title with the current date
    ax.set_title(f"Solar System Simulation - Date: {current_time.iso[:10]}", fontsize=16)

# Main function to set up the animation
def main():
    # Input initial year, month, and day
    year = int(input("Enter the starting year (AD): "))
    month = int(input("Enter the starting month (1-12): "))
    day = int(input("Enter the starting day (1-31): "))

    # Validate the input date
    try:
        date_str = f'{year}-{month:02d}-{day:02d}'
        start_time = Time(date_str, format='iso', scale='utc')
    except Exception as e:
        print(f"Invalid date: {e}")
        return

    # Create the figure and axis
    fig, ax = plt.subplots(figsize=(10, 10))
    ax.set_title("Solar System Simulation", fontsize=16)
    ax.set_xlabel("X Position (AU)", fontsize=14)
    ax.set_ylabel("Y Position (AU)", fontsize=14)
    ax.axhline(0, color='gray', linestyle='--', linewidth=0.5)
    ax.axvline(0, color='gray', linestyle='--', linewidth=0.5)
    ax.grid(alpha=0.3)

    # Plot the Sun at the center
    sun = ax.scatter(0, 0, color='yellow', s=200, label='Sun')

    # Initialize scatter plots and labels for planets
    scatters = []
    labels = []
    initial_positions = get_planet_positions(start_time)
    for planet in PLANETS:
        x, y = initial_positions[planet]
        scatter = ax.scatter(x, y, label=planet.capitalize(), s=50)
        label = ax.text(x, y, f'  {planet.capitalize()}', fontsize=10)
        scatters.append(scatter)
        labels.append(label)

    # Add legend
    ax.legend(loc='upper right')
    ax.axis('equal')

    # Set up the animation
    time_step_days = 1  # Days per frame (adjust for faster/slower simulation)
    ani = FuncAnimation(
        fig,
        animate,
        frames=365,  # Number of frames (e.g., one year of simulation)
        interval=50,  # Milliseconds per frame (controls animation speed)
        fargs=(start_time, ax, scatters, labels, time_step_days),
        repeat=False
    )

    # Show the animation
    plt.show()

if __name__ == "__main__":
    main()