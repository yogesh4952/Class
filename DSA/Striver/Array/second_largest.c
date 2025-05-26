#include <stdio.h>
int second_largest(int arr[], int n)
{
    int largest = arr[0], s_largest = -1;

    if (n == 1)
    {
        return -1;
    }

    if (n == 2 && arr[0] == arr[1])
    {
        return -1;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            s_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > s_largest && arr[i] < largest)
        {
            s_largest = arr[i];
        }
    }

    return s_largest;
}
int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int ans = second_largest(arr, 6);
    printf("%d\n", ans);
    return 0;
}