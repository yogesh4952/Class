#include <stdio.h>

double result(double coeff[], int n, double x)
{
    double result = coeff[0];
    for (int i = 1; i < n; i++)
    {
        result = result * x + coeff[i];
    }
    return result;
}
int main()
{

    int n;
    double x;
    printf("Enter the degree of the polynomial:");
    scanf("%d", &n);

    double coeff[n];
    printf("Enter the coefficients (from highest to lowest degree):\n");
    for (int i = 0; i <= n; i++)
    {
        printf("Coefficient of x^%d: ", n - i);
        scanf("%lf", &coeff[i]);
    }

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("\nIter Intermediate Value Result\n");

    double result = coeff[0];

    printf("%3d  %0.6lf    %0.06\n", coeff[0], result);

    for (int i = 1; i <= n; i++)
    {
        result = result * x + coeff[i];
        printf("%3d  %0.6lf     %0.6lf\n", i + 1, result, result);
    }
    printf("\nPolynomial result at x = %2lf is %.6lf\n", x, result);
    return 0;
}

//? Algorithm
//& 1. Read the order of function 'n' and coefficient ai
//& 2. Read the value of x where value should be determined
//& 3. Set Pn = an
//& 4. For i=n-1 to 0
//^ Pi = Pi+1 *x + ai
//& 5. Print functional value at x=P0
//& 6. End