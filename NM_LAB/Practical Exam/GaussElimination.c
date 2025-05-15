#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3 // Size of the matrix (n x n)

// Function to perform Gauss Elimination
void gauss_elimination(double A[N][N], double b[N], double x[N])
{
    double ratio;
    int i, j, k;

    // Forward Elimination
    for (i = 0; i < N - 1; i++)
    {
        // Check for zero pivot
        if (fabs(A[i][i]) < 1e-10)
        {
            printf("Pivot element is zero at row %d. Method fails.\n", i);
            exit(1);
        }

        for (j = i + 1; j < N; j++)
        {
            ratio = A[j][i] / A[i][i];
            for (k = i; k < N; k++)
            {
                A[j][k] -= ratio * A[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }

    // Back Substitution
    for (i = N - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for (j = i + 1; j < N; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        if (fabs(A[i][i]) < 1e-10)
        {
            printf("Zero diagonal element at row %d. Method fails.\n", i);
            exit(1);
        }
        x[i] /= A[i][i];
    }
}

// Function to print the matrix and vector
void print_system(double A[N][N], double b[N])
{
    printf("Augmented Matrix [A|b]:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.4f ", A[i][j]);
        }
        printf("| %.4f\n", b[i]);
    }
}

// Function to print the solution
void print_solution(double x[N])
{
    printf("Solution:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }
}

int main()
{
    // Example system: 2x + y - z = 8, -3x - y + 2z = -11, -2x + y + 2z = -3
    double A[N][N] = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}};
    double b[N] = {8, -11, -3};
    double x[N];

    printf("Gauss Elimination Method\n\n");
    print_system(A, b);

    gauss_elimination(A, b, x);

    printf("\nAfter Gauss Elimination:\n");
    print_system(A, b); // Matrix A is now upper triangular
    printf("\n");
    print_solution(x);

    return 0;
}