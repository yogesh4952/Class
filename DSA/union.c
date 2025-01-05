#include <stdio.h>

int main()
{
    union myUnion
    {
        int x;
        char y;
        double z;
        float a;
    };

    union myUnion u;
    u.x = 100;
    printf("The value of x is %d\n", u.x);
    u.y = 'B';
    printf("The value of y is %c\n", u.y);
    u.z = 123.456789;
    printf("The value of z is %lf\n", u.z);
    u.a = 45.67;
    printf("The value of a is %f\n", u.a);

    return 0;
}