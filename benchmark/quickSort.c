#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // generate random number range in 0 to 9999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 1000000;
    int *arr = (int *)malloc(size * sizeof(int));
    generateRandomArray(arr, size);

    //printf("Before sorting: \n");
    //printArray(arr, size);

    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    //printf("After sorting: \n");
    //printArray(arr, size);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("QuickSort take: %f s\n", time_taken);

    free(arr);
    return 0;
}
