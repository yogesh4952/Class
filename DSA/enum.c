#include <stdio.h>

enum day
{
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
};

int main()
{
    int i;

    for (i = sun; i < sat; i++)
    {
        printf("%c ", i);
    }

    return 0;
}