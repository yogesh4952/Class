#include <stdio.h>

void shellSort(int arr[], int size)
{
    int gap = size / 2; // Start with gap as half the array size
    while (gap > 0)
    { // Continue until gap becomes 0
        for (int i = gap; i < size; i++)
        {                      // Iterate through elements starting at gap
            int temp = arr[i]; // Save current element
            int j = i;         // Initialize j to current index

            // Shift larger.Concurrent elements that are gap apart
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap]; // Move larger element forward
                j -= gap;              // Move back by gap
            }
            arr[j] = temp; // Place temp in its final position
        }
        gap /= 2; // Reduce gap
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1}; // Input array
    int size = 5;
    shellSort(arr, size); // Sort the array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // Print sorted array
    }
    printf("\n");
    return 0;
}