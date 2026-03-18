#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// [Include the three sorting functions here: bubbleSort, selectionSort, insertionSort]

void benchmark(int size, int type)
{
    int *arr = (int *)malloc(size * sizeof(int));
    // Fill array based on type: 0-Sorted, 1-Random, 2-Reverse
    for (int i = 0; i < size; i++)
    {
        if (type == 0)
            arr[i] = i;
        else if (type == 1)
            arr[i] = rand() % 1000;
        else
            arr[i] = size - i;
    }

    clock_t start = clock();
    // Call the specific sorting function here
    // insertionSort(arr, size);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Size: %d | Time: %f seconds\n", size, time_taken);
    free(arr);
}

int main()
{
    // Nested loops to test all sizes, types, and algorithms
    return 0;
}