#include <stdio.h>

int onesComplement(int x)
{
    int ans = 0;
    int rem;
    int power = 1;
    while (x != 0)
    {
        rem = x % 10;
        if (rem == 0)
        {
            ans = ans + 1 * power;
        }
        // No need for else, as 0*power is already 0
        power *= 10;
        x = x / 10;
    }

    return ans;
}

int main()
{
    int ans = onesComplement(100001); // Binary input (as int)
    printf("%d\n", ans);              // Expected output: 011110
    return 0;
}
