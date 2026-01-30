#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// --- BUBBLE SORT ---
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// --- SELECTION SORT ---
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// --- INSERTION SORT ---
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to reset/fill array based on case
void fillArray(int arr[], int n, int caseType) {
    if (caseType == 0) { // Sorted
        for (int i = 0; i < n; i++) arr[i] = i;
    } else if (caseType == 1) { // Random
        for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    } else { // Reverse
        for (int i = 0; i < n; i++) arr[i] = n - i;
    }
}

void runBenchmark(int size) {
    int *original = (int *)malloc(size * sizeof(int));
    int *testArr = (int *)malloc(size * sizeof(int));
    char *cases[] = {"Sorted", "Random", "Reverse"};
    
    printf("\n>> TESTING DATASET SIZE: %d <<\n", size);
    printf("%-15s | %-12s | %-12s | %-12s\n", "Case", "Bubble (s)", "Selection (s)", "Insertion (s)");
    printf("--------------------------------------------------------------------------\n");

    for (int c = 0; c < 3; c++) {
        double times[3];
        fillArray(original, size, c);

        // 1. Benchmark Bubble Sort
        memcpy(testArr, original, size * sizeof(int));
        clock_t start = clock();
        for(int m=0; m<100; m++) bubbleSort(testArr, size); // Run 100x for measurable time
        times[0] = (double)(clock() - start) / CLOCKS_PER_SEC;

        // 2. Benchmark Selection Sort
        memcpy(testArr, original, size * sizeof(int));
        start = clock();
        for(int m=0; m<100; m++) selectionSort(testArr, size);
        times[1] = (double)(clock() - start) / CLOCKS_PER_SEC;

        // 3. Benchmark Insertion Sort
        memcpy(testArr, original, size * sizeof(int));
        start = clock();
        for(int m=0; m<100; m++) insertionSort(testArr, size);
        times[2] = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("%-15s | %-12.5f | %-12.5f | %-12.5f\n", cases[c], times[0], times[1], times[2]);
    }
    free(original);
    free(testArr);
}

int main() {
    srand(time(NULL));
    int sizes[] = {32, 128, 512};

    printf("Starting Performance Analysis...\n");
    for (int i = 0; i < 3; i++) {
        runBenchmark(sizes[i]);
    }

    return 0;
}