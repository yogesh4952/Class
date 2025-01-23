#include <stdio.h>
#include <math.h>

long long convert(long long n)
{
  long long dec = 0;
  int i = 0, rem;

  while (n != 0)
  {
    rem = n % 10;

    dec += rem << i;
    n /= 10;
    ++i;
  }

  return dec;
};

int main()
{
  long long n;

  printf("Enter a binary number: ");
  scanf("%ld", &n);

  printf("%ld in binary = %ld in decimal", n, convert(n));
  return 0;
}
