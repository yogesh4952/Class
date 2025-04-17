#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = __INT_MAX__;
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
    int arr[] = {1, 1, 1, 1, 2, 2, 3, 4, 5, 6};
    int ans = binarySearch(arr, 10, 2);
    printf("%d\n", ans);
}