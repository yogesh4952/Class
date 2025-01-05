#include <stdio.h>
int main()
{
    int a = 4;
    char *b = "Y";
    float c = 2.1245;
    double d = 12.2656565465;

    printf("%d, %c, %f, %lf", a, *b, c, d);
    return 0;
}