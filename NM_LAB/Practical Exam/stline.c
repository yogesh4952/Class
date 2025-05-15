#include <stdio.h>

#define N 5 // Number of data points

// Function to calculate slope (m) and intercept (c) using least squares
void linear_regression(double x[], double y[], int n, double *m, double *c)
{
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    int i;

    // Calculate sums
    for (i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    // Calculate slope (m) and intercept (c)
    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    *c = (sum_y - *m * sum_x) / n;
}

// Function to print data points
void print_data(double x[], double y[], int n)
{
    printf("Data Points:\n");
    printf("x\t\ty\n");
    printf("----------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t\t%.2f\n", x[i], y[i]);
    }
}

int main()
{
    // Example data points
    double x[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[N] = {2.1, 4.0, 5.9, 8.1, 10.0};
    double m, c;

    printf("Linear Regression for Straight Line Fitting\n\n");
    print_data(x, y, N);

    // Perform linear regression
    linear_regression(x, y, N, &m, &c);

    // Print results
    printf("\nBest-fit line: y = %.4fx + %.4f\n", m, c);

    // Calculate and print predicted values
    printf("\nPredicted vs Actual:\n");
    printf("x\tActual y\tPredicted y\n");
    printf("--------------------------------\n");
    for (int i = 0; i < N; i++)
    {
        double y_pred = m * x[i] + c;
        printf("%.2f\t%.2f\t\t%.2f\n", x[i], y[i], y_pred);
    }

    return 0;
}