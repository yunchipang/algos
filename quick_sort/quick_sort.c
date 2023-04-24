// Quick Sort
#include <stdio.h>

#define SIZE 10

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int* arr, int start, int end) {

    int pivot = arr[end];
    int greaterElemIndex = start-1; // pointer for greater element
    int tmp;

    for (int i=start; i<end; i++) {
        if (arr[i] <= pivot) {
            greaterElemIndex++;
            swap(&arr[i], &arr[greaterElemIndex]);
        }
    }
    swap(&arr[end], &arr[greaterElemIndex+1]);
    return greaterElemIndex+1; // return the partition point
}

void quicksort(int* arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}

int main() {
    int arr[] = {4,10,8,7,6,2,3,12,14,5};

    quicksort(arr, 0, SIZE-1);

    for(int i = 0; i< SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
