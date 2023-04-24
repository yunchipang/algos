// Merge Sort
#include<stdio.h> 

#define SIZE 10

void combine(int *arr,int left, int mid, int right) { 
    int leftP = left;
    int rightP = mid+1;
    int tmpP = left;
    int tmp[SIZE];

    // combining left part and right part in sorted order
    while (leftP <= mid && rightP <= right) {
        if (arr[leftP] <= arr[rightP]) {
            tmp[tmpP++] = arr[leftP++]; // item at leftP goes to tmp arr
        } else {
            tmp[tmpP++] = arr[rightP++];
        }
    }
    // move the remaining
    while (leftP <= mid) {
        tmp[tmpP++] = arr[leftP++];
    }
    while (rightP <= right) {
        tmp[tmpP++] = arr[rightP++];
    }

    // move items at tmp back to arr
    for(int i=left; i<=right; i++){
        arr[i] = tmp[i];
    }
} 

void divide(int *arr, int left, int right) 
{ 
    int mid; 

    if(left < right) { 
        mid = (left+right)/2; 
        divide(arr, left, mid); 
        divide(arr, mid+1, right); 

        combine(arr, left, mid, right); 
    } 
}

int main() { 
    int arr[] = {10,-3,7,15,90,8,0,-5};

    divide(arr,0,SIZE-1); 

    for(int i = 0; i<SIZE; i++) {
        printf("%d ",arr[i]); 
    }
    return 0;
} 

