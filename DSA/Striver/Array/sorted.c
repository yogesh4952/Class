#include <stdio.h>
#include <stdlib.h>

int isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int arr[] = {2, 1, 2, 23, 2, 4, 4};
    int arr2[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int arr3[] = {3, 4, 5, 1, 2};

    if (isSorted(arr3, 5))
    {
        printf("Array is sorted\n");
    }
    else
    {
        printf("Array is not sorted\n");
    }
}