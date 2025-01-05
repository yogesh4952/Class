#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;

    printf("The value of x is %d\n", x);
    printf("The address of x is %p\n", p);

    *p = 20;

    printf("The value of x is %d\n", x);
    printf("The value of *p is %d\n", *p);

    return 0;
}