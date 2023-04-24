// Selection Sort with Swap
#include <stdio.h>

void selection_sort(int* arr, int count)
{
    int min_idx, temp;
    // Enter Your code here
    for (int i=0; i<count; i++) {
        min_idx = i;
        for (int j=i+1; j<count; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    int numArr[] = { 2, 25, 10, 45, 1};
    int count = sizeof(numArr) / sizeof(int); 

    selection_sort(numArr, count);

    for (int i = 0; i < count; i++)
        printf("%d ", numArr[i]);
    printf("\n");

    return 0;
}
