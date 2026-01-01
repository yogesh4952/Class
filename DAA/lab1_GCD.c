#include <stdio.h>

int findGCD(int a, int b)
{
  while (b != 0)
  {

    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
int main()
{
  int num1, num2;
  printf("Enter two number:");
  scanf("%d%d", &num1, &num2);
  int ans = findGCD(num1, num2);
  printf("%d", ans);
  return 0;
}