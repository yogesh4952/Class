#include <stdio.h>

// Define the differential equation: dy/dx = f(x, y)
double f(double x, double y)
{
    // Example: dy/dx = -2x * y
    return -2.0 * x * y;
}

// Function to perform one step of 4th-order Runge-Kutta
double rk4_step(double x, double y, double h)
{
    double k1, k2, k3, k4;

    // Calculate the four RK4 coefficients
    k1 = f(x, y);
    k2 = f(x + h / 2, y + h * k1 / 2);
    k3 = f(x + h / 2, y + h * k2 / 2);
    k4 = f(x + h, y + h * k3);

    // Compute the next y value
    return y + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
}

int main()
{
    double x0 = 0.0;                           // Initial x
    double y0 = 1.0;                           // Initial y
    double x_end = 1.0;                        // End of interval
    double h = 0.1;                            // Step size
    int steps = (int)((x_end - x0) / h + 0.5); // Number of steps

    double x = x0, y = y0;

    // Print header
    printf("4th-Order Runge-Kutta Method\n");
    printf("Solving dy/dx = -2x*y, y(0) = 1\n");
    printf("Step size h = %.2f\n\n", h);
    printf("x\t\ty\n");
    printf("----------------\n");
    printf("%.4f\t%.6f\n", x, y);

    // Iterate using RK4
    for (int i = 0; i < steps; i++)
    {
        y = rk4_step(x, y, h);
        x += h;
        printf("%.4f\t%.6f\n", x, y);
    }

    printf("\nFinal value: y(%.4f) = %.6f\n", x, y);

    return 0;
}