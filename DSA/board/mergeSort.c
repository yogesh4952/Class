#include <stdio.h>
#define size 1000
int top = -1;

void push(int arr[], int x)
{
    if (top == size - 1)
        return;
    else
    {
        ++top;
        arr[top] = x;
    }
}

void ms(int arr[], int low, int mid, int high)
{
    int left = low;
    int temp[size] = {0};
    int right = mid + 1;
    top = -1; // Reset top for each merge

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            push(temp, arr[left]);
            left++;
        }
        else
        {
            push(temp, arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        push(temp, arr[left]);
        left++;
    }

    while (right <= high)
    {
        push(temp, arr[right]);
        right++;
    }

    // Corrected copy-back
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    ms(arr, low, mid, high);
}

int main()
{
    int arr[] = {5, 4, 3, 21, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1); // Corrected

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
