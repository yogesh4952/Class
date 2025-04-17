#include <stdio.h>

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int main()
{
    int ans = GCD(4, 6);
    printf("%d", ans);
    return 0;
}