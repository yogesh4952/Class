#include <stdio.h>

int main()
{

    float x[10], f[10], y, sum = 0.0, l;
    int n, i, j;

    printf("\nInput number of data: ");
    scanf("%d", &n);
    printf("\nInput data points x(l)&f(i):\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("f[%d]=", i);
        scanf("%f", &f[i]);
    }
    printf("\nFunctional value(y):");
    scanf("%f", &y);
    for (i = 0; i < n; i++)
    {
        l = 1;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                l = l * (y - x[j]) / (x[i] - x[j]);
            }
        }
        sum = sum + l * f[i];
    }
    printf("\nValue at %f=%f", y, sum);
    return 0;
}
/*&
  1. Start
  2. Input
      . Read the number of data points, say n
      . Read the value at which interpolation is needed, say y
      . Read the data points x[i] and their corresponding function values f[i] for
        i=0 to n-1
  3. Initialize
      . Set sum =0;
  4. Calculate Langrage Basics Polynomials Li:
      .For i=0 to n-1
        o Set l =1
        o For j=0 to n-1
            * if j!=i;
                . Compute
                    => l =l * (y-x[j])/(x[i]-x[j])

            * End if
      . End for j
      .Update
          sum = sum + l * f[i]
      .End for i
  5. Output Interpolated Value:
    .Print sum as the interpolated value at y.
  6. End/ Terminate
*/