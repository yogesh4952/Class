#include <stdio.h>

int dec_bin(int x)
{
    int ans = 0, power = 1, rem;
    while (x != 0)
    {
        rem = x % 2;
        ans = ans + rem * power;
        power = power * 10;
        x = x / 2;
    }
    return ans;
}
int main()

{
    int ans = dec_bin(7);

    for (int i = 1; i < 10; i++)
    {
        int ans = dec_bin(i);
        printf("%d\n", ans);
        
    }
    return 0;
}