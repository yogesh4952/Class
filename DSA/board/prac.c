#include <stdio.h>
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 21, 2};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
}
