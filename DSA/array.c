#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("The value of arr[%d] is %d\n", i + 1, arr[i]);
    }
}