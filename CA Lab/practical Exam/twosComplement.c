#include <stdio.h>

int twosComp(int x)
{
    int ones = 0;
    int rem;
    int power = 1;
    while (x != 0)
    {
        rem = x % 10;
        if (rem == 0)
        {
            ones = ones + 1 * power;
        }
        // No need for else, as 0*power is already 0
        power *= 10;
        x = x / 10;
    }

    int twoRem = ones % 10;
    int twoAns;
    power = 1;
    if (twoRem != 0)
    {
        twoAns = twoAns + twoRem + 1;
    }
}

int main()
{
    return 0;
}