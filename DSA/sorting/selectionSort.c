#include <stdio.h>
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    selectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d\t", arr[i]);
    }
}