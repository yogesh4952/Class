#include <stdio.h>

int bs(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int ans = bs(arr, 5, 4);
    printf("%d\n", ans);
}