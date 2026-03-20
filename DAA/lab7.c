#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sorting functions
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function pointer type for sorting functions
typedef void (*sort_func)(int[], int);

void benchmark(int size, int type, sort_func sort, const char *algo_name)
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
    sort(arr, size);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Algorithm: %s | Type: %d | Size: %d | Time: %f seconds\n", algo_name, type, size, time_taken);
    free(arr);
}

int main()
{
    srand(time(NULL)); // Seed random number generator

    // Define sorting functions and names
    sort_func sorts[3] = {bubbleSort, selectionSort, insertionSort};
    const char *names[3] = {"Bubble Sort", "Selection Sort", "Insertion Sort"};

    // Array sizes to test
    int sizes[] = {100, 1000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Array types: 0-Sorted, 1-Random, 2-Reverse
    int types[] = {0, 1, 2};
    int num_types = sizeof(types) / sizeof(types[0]);

    // Nested loops to test all sizes, types, and algorithms
    for (int s = 0; s < num_sizes; s++)
    {
        for (int t = 0; t < num_types; t++)
        {
            for (int a = 0; a < 3; a++)
            {
                benchmark(sizes[s], types[t], sorts[a], names[a]);
            }
        }
    }

    return 0;
}