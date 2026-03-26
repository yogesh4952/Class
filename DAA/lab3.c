#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Sequential Search
int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void run_test(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        arr[i] = i * 2;
    // Sorted array

    int targets[] = {arr[0], arr[size / 2], arr[size - 1], -1};
    char *labels[] = {"Initial", "Mid", "Last", "Not Found"};
    int iterations = 100000;

    printf("\n--- Array Size: %d ---\n", size);
    printf("%-12s | %-15s | %-15s\n",
           "Position", "Seq Search (s)", "Bin Search (s)");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < 4; i++)
    {
        clock_t start, end;

        start = clock();
        for (int j = 0; j < iterations; j++)
            sequentialSearch(arr, size, targets[i]);
        end = clock();
        double seq_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        for (int j = 0; j < iterations; j++)
            binarySearch(arr, size, targets[i]);
        end = clock();
        double bin_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-12s | %-15.5f | %-15.5f\n",
               labels[i], seq_time, bin_time);
    }
    free(arr);
}

int main()
{
    int sizes[] = {32, 128, 512};
    for (int i = 0; i < 3; i++)
        run_test(sizes[i]);
    return 0;
}