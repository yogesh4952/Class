#include <stdio.h>

#define DEGREE 4 // Degree of the polynomial

// Function to perform Horner's method
// Returns the polynomial value and stores quotient coefficients in quotient[]
double horners_method(double coeffs[], int degree, double x, double quotient[])
{
    double result = coeffs[degree]; // Start with the leading coefficient
    int i;

    // Horner's method: compute value and quotient coefficients
    for (i = degree - 1; i >= 0; i--)
    {
        quotient[i] = result; // Store coefficient of quotient
        result = result * x + coeffs[i];
    }

    return result; // Return p(x) or remainder
}

// Function to print polynomial
void print_polynomial(double coeffs[], int degree)
{
    printf("Polynomial: ");
    for (int i = degree; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%.2f", coeffs[i]);
        }
        else
        {
            printf("%.2fx^%d + ", coeffs[i], i);
        }
    }
    printf("\n");
}

int main()
{
    // Example polynomial: p(x) = 1x^4 - 3x^3 + 2x^2 + 4x - 5
    double coeffs[DEGREE + 1] = {-5, 4, 2, -3, 1}; // Coefficients in ascending order of degree
    double x = 2.0;                                // Point at which to evaluate
    double quotient[DEGREE];                       // To store quotient coefficients
    double value;

    printf("Horner's Method\n\n");
    print_polynomial(coeffs, DEGREE);
    printf("Evaluating at x = %.2f\n\n", x);

    // Perform Horner's method
    value = horners_method(coeffs, DEGREE, x, quotient);

    // Print results
    printf("Value of p(%.2f) = %.4f\n", x, value);
    printf("Quotient polynomial (dividing by x - %.2f): ", x);
    for (int i = DEGREE - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%.2f", quotient[i]);
        }
        else
        {
            printf("%.2fx^%d + ", quotient[i], i);
        }
    }
    printf("\nRemainder: %.4f\n", value);

    return 0;
}