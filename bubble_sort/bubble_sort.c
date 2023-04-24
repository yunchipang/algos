// Bubble Sort

#include <stdio.h>

void bubble_sort(int* arr, int count)
{
    int temp;
    // Enter your code here
    for (int i=0; i<count; i++) {
        for (int j=0; j<count-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int numArr[] = { 2, 25, 10, 45, 1};
    int count = sizeof(numArr) / sizeof(int); 

    bubble_sort(numArr, count);

    for (int i = 0; i < count; i++)
        printf("%d ", numArr[i]);
    printf("\n");

    return 0;
}
