#include <stdio.h>
int function(int n)
{
    if (n == 0)
        return 0;
    return function(n - 1);
}
int main()
{

    for (int i = 0; i < 5; i++)
    {
        printf("%d", function(i));
    }
}