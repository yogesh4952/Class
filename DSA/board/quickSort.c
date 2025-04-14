#include <stdio.h>

int pIndex(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {

        while (arr[i] <= pivot && i < high)
        {
            i++;
        }

        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int partitionIndex = pIndex(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}

int main()
{

    int arr[] = {5, 3, 3, 3, 2, 2, 1, 67};
    quickSort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t", arr[i]);
    }
}