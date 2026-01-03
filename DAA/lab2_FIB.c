#include <stdio.h>

int fib(int n)
{
  if (n == 0 || n == 1)
    return n;

  else
    return fib(n - 1) + fib(n - 2);
}
int main()
{
  int x;
  printf("Enter number:");
  scanf("%d", &x);
  for (int i = 0; i < x; i++)
  {
    printf("%d\t", fib(i));
  }

  return 0;
}