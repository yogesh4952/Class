#include <stdio.h>

int bin_dec(int x)
{
    int rem, ans = 0;

    int subs = 1;

    while (x != 0)
    {
        rem = x % 10;
        ans = ans + rem * subs;
        x = x / 10;
        subs = subs * 2;
    }

    return ans;
}
 
int main()
{
    int ans = bin_dec(101);
    printf("%d\n", ans);
    return 0;
}