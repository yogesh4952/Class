#include <stdio.h>

int main()
{
    int arr[] = {1, 1};

    int count = 0;
    for (int i = 1; i < sizeof(arr) / 4; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            count = count + 1;
        }
    }
    printf("%d\n", count + 1);
}