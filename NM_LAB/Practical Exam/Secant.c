#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
double f(double x)
{
    // Example: f(x) = x^2 - 4
    return x * x - 4;
}

// Secant method implementation
double secant_method(double x0, double x1, double tolerance, int max_iterations)
{
    double x2, f0, f1, f2;
    int iteration = 0;

    // Print header for iteration table
    printf("Iteration |   x0   |   x1   |   x2   |   f(x2)  |\n");
    printf("------------------------------------------------\n");

    while (iteration < max_iterations)
    {
        f0 = f(x0);
        f1 = f(x1);

        // Check if f0 and f1 are equal to avoid division by zero
        if (fabs(f1 - f0) < 1e-10)
        {
            printf("Method failed: Division by zero encountered.\n");
            return x1;
        }

        // Calculate next approximation using secant formula
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        f2 = f(x2);

        // Print current iteration details
        printf("%9d | %.4f | %.4f | %.4f | %.4e |\n",
               iteration, x0, x1, x2, f2);

        // Check for convergence
        if (fabs(f2) < tolerance || fabs(x2 - x1) < tolerance)
        {
            printf("Converged after %d iterations.\n", iteration + 1);
            return x2;
        }

        // Update values for next iteration
        x0 = x1;
        x1 = x2;
        iteration++;
    }

    printf("Method failed to converge within %d iterations.\n", max_iterations);
    return x1;
}

int main()
{
    double x0 = 1.0;          // First initial guess
    double x1 = 3.0;          // Second initial guess
    double tolerance = 1e-6;  // Convergence criterion
    int max_iterations = 100; // Maximum number of iterations

    printf("Secant Method for finding root of f(x) = x^2 - 4\n");
    printf("Initial guesses: x0 = %.4f, x1 = %.4f\n", x0, x1);
    printf("Tolerance: %.4e\n", tolerance);
    printf("Max iterations: %d\n\n", max_iterations);

    double root = secant_method(x0, x1, tolerance, max_iterations);

    printf("\nApproximate root: %.8f\n", root);
    printf("Function value at root: %.8e\n", f(root));

    return 0;
}