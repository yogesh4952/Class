#include <stdio.h>
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{

    int arr[] = {5, 4, 3, 2, 1};
    bubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
}
