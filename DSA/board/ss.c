#include <stdio.h>
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {

        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int arr[] = {4, 4, 3, 2, 1};
    selection_sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
}