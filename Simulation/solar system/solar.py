import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from astropy.time import Time
from astropy.coordinates import get_body_barycentric

# Define the names of the planets
PLANETS = ['mercury', 'venus', 'earth', 'mars', 'jupiter', 'saturn', 'uranus', 'neptune']

def get_planet_positions(year, month, day):
    """
    Calculate the positions of planets for a given date.
    :param year: Year (e.g., 2023)
    :param month: Month (1-12)
    :param day: Day (1-31)
    :return: Dictionary with planet names as keys and their (x, y) positions as values.
    """
    # Create an Astropy Time object for the given date
    date_str = f'{year}-{month:02d}-{day:02d} 00:00:00'
    time = Time(date_str, format='iso', scale='utc')
    
    # Dictionary to store planet positions
    positions = {}
    
    for planet in PLANETS:
        # Get the barycentric position of the planet
        pos = get_body_barycentric(planet, time)
        
        # Extract x and y coordinates (in AU)
        positions[planet] = (pos.x.value, pos.y.value)
    
    return positions

def plot_solar_system(positions):
    """
    Plot the solar system in 2D.
    :param positions: Dictionary of planet positions.
    """
    # Create a figure
    plt.figure(figsize=(10, 10))
    plt.title("Solar System Simulation", fontsize=16)
    plt.xlabel("X Position (AU)", fontsize=14)
    plt.ylabel("Y Position (AU)", fontsize=14)
    plt.axhline(0, color='gray', linestyle='--', linewidth=0.5)
    plt.axvline(0, color='gray', linestyle='--', linewidth=0.5)
    plt.grid(alpha=0.3)
    
    # Plot the Sun at the center
    plt.scatter(0, 0, color='yellow', s=200, label='Sun')
    
    # Plot each planet
    for planet, (x, y) in positions.items():
        plt.scatter(x, y, label=planet.capitalize(), s=50)
        plt.text(x, y, f'  {planet.capitalize()}', fontsize=10)
    
    # Add legend and show the plot
    plt.legend(loc='upper right')
    plt.axis('equal')
    plt.savefig('solar_system.png')
    print("Plot saved as solar_system.png")

def main():
    # Input year, month, and day from the user
    year = int(input("Enter the year (AD): "))
    month = int(input("Enter the month (1-12): "))
    day = int(input("Enter the day (1-31): "))
    
    # Validate the input date
    try:
        date_str = f'{year}-{month:02d}-{day:02d}'
        Time(date_str, format='iso', scale='utc')  # This will raise an error if the date is invalid
    except Exception as e:
        print(f"Invalid date: {e}")
        return
    
    # Get planet positions for the given date
    positions = get_planet_positions(year, month, day)
    
    # Plot the solar system
    plot_solar_system(positions)

if __name__ == "__main__":
    main()