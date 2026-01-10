import numpy as np
import plotly.graph_objects as go
from astropy.time import Time
from astropy.coordinates import get_body_barycentric

# Define the names of the planets and their colors
PLANETS = {
    'mercury': {'color': 'gray'},
    'venus': {'color': 'orange'},
    'earth': {'color': 'blue'},
    'mars': {'color': 'red'},
    'jupiter': {'color': 'brown'},
    'saturn': {'color': 'gold'},
    'uranus': {'color': 'lightblue'},
    'neptune': {'color': 'darkblue'}
}

# Orbital parameters (semi-major axis and eccentricity) for each planet
ORBITAL_PARAMS = {
    'mercury': {'a': 0.387, 'e': 0.2056},
    'venus': {'a': 0.723, 'e': 0.0068},
    'earth': {'a': 1.000, 'e': 0.0167},
    'mars': {'a': 1.524, 'e': 0.0934},
    'jupiter': {'a': 5.203, 'e': 0.0489},
    'saturn': {'a': 9.537, 'e': 0.0565},
    'uranus': {'a': 19.191, 'e': 0.0457},
    'neptune': {'a': 30.069, 'e': 0.0097},
}

def get_planet_positions(time):
    """
    Calculate the positions of planets for a given time.
    :param time: Astropy Time object
    :return: Dictionary with planet names as keys and their (x, y) positions as values.
    """
    positions = {}
    for planet in PLANETS.keys():
        pos = get_body_barycentric(planet, time)
        positions[planet] = (pos.x.value, pos.y.value)  # Only x and y coordinates
    return positions

def create_interactive_plot(year, month, day):
    """
    Create an interactive solar system visualization using Plotly.
    :param year: Year (e.g., 2023 or -4712 for BC)
    :param month: Month (1-12)
    :param day: Day (1-31)
    """
    # Create an Astropy Time object for the given date
    date_str = f'{year}-{month:02d}-{day:02d}'
    try:
        time = Time(date_str, format='iso', scale='utc')
    except Exception as e:
        print(f"Invalid date: {e}")
        return

    # Get the positions of the planets
    positions = get_planet_positions(time)

    # Create the figure
    fig = go.Figure()

    # Add the Sun
    fig.add_trace(go.Scatter(
        x=[0], y=[0],
        mode='markers',
        marker=dict(size=20, color='yellow', opacity=0.8),
        name='Sun',
        text=['Sun'],
        hoverinfo='text'
    ))

    # Add elliptical orbits for each planet
    theta = np.linspace(0, 2 * np.pi, 1000)  # Angles for the orbit
    for planet, params in ORBITAL_PARAMS.items():
        a = params['a']  # Semi-major axis
        e = params['e']  # Eccentricity
        r = a * (1 - e**2) / (1 + e * np.cos(theta))  # Polar equation of an ellipse
        x_orbit = r * np.cos(theta)
        y_orbit = r * np.sin(theta)
        fig.add_trace(go.Scatter(
            x=x_orbit, y=y_orbit,
            mode='lines',
            line=dict(color='gray', width=1, dash='dot'),
            name=f'{planet.capitalize()} Orbit',
            hoverinfo='none'
        ))

    # Add planets
    for planet, (x, y) in positions.items():
        color = PLANETS[planet]['color']
        fig.add_trace(go.Scatter(
            x=[x], y=[y],
            mode='markers',
            marker=dict(size=10, color=color, opacity=0.8),
            name=planet.capitalize(),
            text=[f'{planet.capitalize()}<br>X: {x:.2f} AU<br>Y: {y:.2f} AU'],
            hoverinfo='text'
        ))

    # Update layout
    fig.update_layout(
        title=f"Solar System Simulation - Date: {date_str}",
        xaxis_title="X Position (AU)",
        yaxis_title="Y Position (AU)",
        showlegend=True,
        template='plotly_dark',
        width=800,
        height=800,
        scene_aspectmode='data'
    )

    # Show the plot
    fig.show()

def main():
    # Input year, month, and day from the user
    year = int(input("Enter the year (AD or BC): "))
    month = int(input("Enter the month (1-12): "))
    day = int(input("Enter the day (1-31): "))

    # Create the interactive plot
    create_interactive_plot(year, month, day)

if __name__ == "__main__":
    main()