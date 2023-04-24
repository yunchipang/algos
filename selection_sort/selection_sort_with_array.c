// Selection Sort with 2 arrays
#include <stdio.h>

void selection_sort(int* arr, int* sort, int count)
{
    int min_idx;
    // Enter Your code here

    for (int i=0; i<count; i++) {
        min_idx = i;
        for (int j=0; j<count; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        sort[i] = arr[min_idx];
        arr[min_idx] = 9999999;
    }
}

int main()
{
    int numArr[] = { 2, 25, 10, 45, 1};
    int count = sizeof(numArr) / sizeof(int); 
    int sortArr[count];

    selection_sort(numArr, sortArr, count);

    for (int i = 0; i < count; i++)
        printf("%d ", sortArr[i]);
    printf("\n");

    return 0;
}
