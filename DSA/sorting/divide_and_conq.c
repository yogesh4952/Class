#include <stdio.h>
#include <stdlib.h>

// Merge Sort
void merge(int *arr, int l, int m, int r)
{
    int i = l, j = m + 1, k = 0, *temp = malloc((r - l + 1) * sizeof(int));
    while (i <= m && j <= r)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++)
        arr[i] = temp[k++];
    free(temp);
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int pivot = arr[h], i = l - 1;
        for (int j = l; j < h; j++)
            if (arr[j] <= pivot)
                swap(&arr[++i], &arr[j]);
        swap(&arr[i + 1], &arr[h]);
        int pi = i + 1;
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

// Heap Sort
void heapify(int *arr, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Display
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1}, n = 5;

    mergeSort(arr, 0, n - 1);
    printf("Merge: ");
    display(arr, n);

    int arr2[] = {5, 4, 3, 2, 1};
    quickSort(arr2, 0, n - 1);
    printf("Quick: ");
    display(arr2, n);

    int arr3[] = {5, 4, 3, 2, 1};
    heapSort(arr3, n);
    printf("Heap: ");
    display(arr3, n);

    return 0;
}