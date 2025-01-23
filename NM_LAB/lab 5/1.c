#include <stdio.h>
#define MAX 15
int main()
{
  int n;
  float xp, fp, sum, pi, x[MAX], f[MAX], a[MAX], d[MAX][MAX];

  char q;
  printf("\ninput the number of data pairs:");
  scanf("%d", &n);

  printf("\n Input all data pairs (x(i)andf(i))sequentially:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f%f", &x[i], &f[i]);
    d[i][0] = f[i];
  }
  for (int j = 1; j < n; j++)
  {
    for (int i = 0; i < n - j; i++)
    {
      d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j] - x[i]);
    }
  }
  for (int j = 0; j < n; j++)
  {
    a[j] = d[0][j];
  }
  do
  {
    printf("\ninput x at which interpolation is required:");
    scanf("%f", &xp);

    sum = a[0];
    for (int i = 1; i < n; i++)
    {
      pi = 1.0;
      for (int j = 0; j < i; j++)
      {
        pi *= (xp - x[j]);
      }
      sum += a[i] * pi;
    }
    fp = sum;
    printf("\nInterpolated function value at x=%f is %f.\n", xp, fp);
    printf("Do you want to input another value?(y/n):");
    scanf("%c", &q);

  } while (q == 'y');
  return 0;
}