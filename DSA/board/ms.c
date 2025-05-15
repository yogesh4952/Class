#include <stdio.h>
int top = -1;
#define size 100

void push(int arr[], int x)
{
    if (top == size - 1)
    {
        return;
    }
    arr[++top] = x;
}

void ms(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    int temp[] = {0};
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
}