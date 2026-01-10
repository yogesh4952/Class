import numpy as np
import plotly.graph_objects as go
from astropy.time import Time
from astropy.coordinates import get_body_barycentric
from astropy import units as u
import warnings

# Suppress specific warnings from astropy and ERFA
warnings.filterwarnings("ignore", category=UserWarning, module="astropy.time.core")
warnings.filterwarnings("ignore", category=UserWarning, module="erfa.core")

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

def create_live_plot(start_year, start_month, start_day, num_days=365, interval_days=1):
    """
    Create a live solar system visualization using Plotly.
    :param start_year: Starting year (AD or BC)
    :param start_month: Starting month (1-12)
    :param start_day: Starting day (1-31)
    :param num_days: Number of days to simulate
    :param interval_days: Days between frames
    """
    # Validate interval_days
    if interval_days > 10000:  # Limit to ~27 years (10,000 days)
        print(f"Error: Interval ({interval_days} days) is too large. Maximum allowed is 10,000 days.")
        return

    # Create an Astropy Time object for the starting date
    start_date_str = f'{start_year}-{start_month:02d}-{start_day:02d}'
    try:
        start_time = Time(start_date_str, format='iso', scale='utc')
    except Exception as e:
        print(f"Invalid date: {e}")
        return

    # Generate timestamps for the simulation
    interval = interval_days * u.day  # Explicitly specify units
    times = [start_time + i * interval for i in range(num_days)]

    # Precompute planet positions for all timestamps
    all_positions = []
    for time in times:
        positions = get_planet_positions(time)
        all_positions.append(positions)

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

    # Add traces for planets (initially empty)
    planet_traces = {}
    for planet in PLANETS.keys():
        color = PLANETS[planet]['color']
        fig.add_trace(go.Scatter(
            x=[], y=[],
            mode='markers',
            marker=dict(size=10, color=color, opacity=0.8),
            name=planet.capitalize(),
            text=[],
            hoverinfo='text'
        ))
        planet_traces[planet] = len(fig.data) - 1  # Track the index of each planet's trace

    # Update layout
    fig.update_layout(
        title="Live Solar System Simulation",
        xaxis_title="X Position (AU)",
        yaxis_title="Y Position (AU)",
        showlegend=True,
        template='plotly_dark',
        width=800,
        height=800,
        scene_aspectmode='data',
        updatemenus=[{
            "type": "buttons",
            "buttons": [{
                "label": "Play",
                "method": "animate",
                "args": [None, {"frame": {"duration": 50, "redraw": True}, "fromcurrent": True}]
            }, {
                "label": "Pause",
                "method": "animate",
                "args": [[None], {"frame": {"duration": 0, "redraw": False}, "mode": "immediate"}]
            }]
        }]
    )

    # Create frames for the animation
    frames = []
    for i, positions in enumerate(all_positions):
        frame_data = []
        for planet, (x, y) in positions.items():
            frame_data.append(go.Scatter(
                x=[x], y=[y],
                mode='markers',
                marker=dict(size=10, color=PLANETS[planet]['color'], opacity=0.8),
                text=[f'{planet.capitalize()}<br>X: {x:.2f} AU<br>Y: {y:.2f} AU'],
                hoverinfo='text'
            ))
        frames.append(go.Frame(data=frame_data))

    # Add frames to the figure
    fig.frames = frames

    # Show the plot
    fig.show()

def main():
    # Input starting year, month, and day from the user
    start_year = int(input("Enter the starting year (AD or BC): "))
    start_month = int(input("Enter the starting month (1-12): "))
    start_day = int(input("Enter the starting day (1-31): "))

    # Input number of days to simulate and interval between frames
    num_days = int(input("Enter the number of days to simulate: "))
    interval_days = int(input("Enter the interval between frames (in days): "))

    # Validate inputs
    if interval_days <= 0:
        print("Error: Interval must be greater than 0.")
        return
    if num_days <= 0:
        print("Error: Number of days must be greater than 0.")
        return

    # Create the live plot
    create_live_plot(start_year, start_month, start_day, num_days, interval_days)

if __name__ == "__main__":
    main()