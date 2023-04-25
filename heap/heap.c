#include <stdio.h>

#define MAX_SIZE 1000
#define SWAP(x,y,z) z=x, x=y, y=z
int heap[MAX_SIZE];

// function define
void heappush(int, int*);
void heappop(int*);
void adjust(int, int);
void heapprint(int);

// heap push
void heappush(int data, int* size) {

    // size+1 bc an additional node is pushed into heap
    int i = ++(*size);

    // overflow error
    if (i >= MAX_SIZE) {
        printf("(error) heap full\n");
        return;
    }

    // switch with a parent till location
    while (i != 1 && heap[i/2] > data) {
        heap[i] = heap[i/2];
        i = i / 2;
    }

    // push data into heap
    heap[i] = data;
}

// heap pop, size is the number of data
void heappop(int *size) {
    int temp = 0;
    
    printf("heap pop: %d\n", heap[1]); // pop from the top
    SWAP(heap[1], heap[*size], temp); // temp=heap[1], heap[1]=heap[*size], heap[*size]=temp
                                      // (move the last leave to the top) 
    (*size)--;
    adjust(1, (*size));
}

// adjust the location among children
void adjust(int parent, int size) {

    int child = parent * 2; 
    int p_data = heap[parent];
    
    while (child+1 <= size) {
        // compare 2 children, find the smaller one
        if (heap[child] > heap[child+1]) {
            child++;
        }
        // swap parent with its smaller child
        if (heap[child] > p_data) { // child > parent: position found
            break;
        } else {
            heap[child/2] = heap[child];
            child *= 2;
        }
    }
    heap[child/2] = p_data;
}

// display
void heapprint(int size) {
    printf("current heap\n");
    int cnt = 2;
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
        if (i == cnt -1) {
            printf("\n");
            cnt = cnt * 2;
        }
    }
    printf("\n");
}

int main() {
    int menu = 0;
    int value = 0;
   int size = 0;

    while (menu <= 3) {
        heapprint(size);
        printf("\nmenu \n1.add (push)\n2.delete (pop)\n3.exit \n\n");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("enter value to push: ");
            scanf("%d", &value);
            heappush(value, &size);
            break;
        case 2:
            printf("enter value to pop");
            if (size == 0) {
                printf("(error) empty heap\n");
                break;
            }
            heappop(&size);
            break;
        case 3:
            menu = 4;
            break;
        }
    }
}
