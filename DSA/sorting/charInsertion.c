#include <stdio.h>
void insertionSort(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main()
{

    char arr[] = {'a', 'b', 'v', 'e', 'd'};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%c\t", arr[i]);
    }

    return 0;
}
