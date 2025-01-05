// Fasle itteration method

#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define ERROR 0.0001

double f(double x)
{
  // return x * log_base(x) - 1.2;
  // return x * x * x - x - 1;
  return 10 -
         2.1 * x - 0.001 * x * x * x;
}

void regulaFalsi(double a, double b)
{
  if (f(a) * f(b) >= 0)
  {
    printf("Invalid internal. The function does not have a root in the given range.\n");
    return;
  }

  double c;
  int iterations = 0;
  printf("Iter a b c f(c)n");
  while (iterations < MAX_ITERATIONS)
  {
    c = (a * f(b) - b * f(a)) / (f(b) - f(a));
    printf("%-5d %-10.6f %-10.6f %-10.6f %-10.6f\n", iterations + 1, a, b, c, f(c));

    if (fabs(f(c)) < ERROR)
    {
      printf("\nRoot is approximately %.6f\n", c);
      printf("f(root) = %.6f\n", f(c));
      return;
    }

    if (f(c) * f(a) < 0)
    {
      b = c;
    }
    else
    {
      a = c;
    }

    iterations++;
  }

  printf("\nMaximum iterations reached. Approximate root: %.6f\n", c);
  printf("f(root) = %.6f\n", f(c));
}

int main()
{
  double a, b;

  printf("Enter the interval [a, b]: ");
  scanf("%lf %lf", &a, &b);

  regulaFalsi(a, b);

  return 0;
}