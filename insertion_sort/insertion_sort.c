// Insertion Sort
#include <stdio.h>

void insertion_sort(int* arr, int count){
    int i, j, key;
    // Enter your code here
    for (i=1; i<count; i++) {
        key = arr[i];
        // for (j=i-1; j>=0 && arr[j]>key; j--) {
        //     arr[j+1] = arr[j];
        // }
        j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int numArr[] = { 2, 25, 10, 45, 1};
    int count = sizeof(numArr) / sizeof(int); 

    insertion_sort(numArr, count);

    for (int i = 0; i < count; i++)
        printf("%d ", numArr[i]);
    printf("\n");

    return 0;
}
