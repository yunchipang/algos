#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// max number of inputs
#define MAX_INPUT 100

// max random number
#define RAND_RANGE 100

// swap the contents of integers *i and *j
// we must pass the ints by reference so the function can change them
void swap(int* i, int* j) {
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
  return;
}


// ====================== MAX HEAP DEFINITIONS ======================

// max size of heap
#define LIMIT 200

// heap will be a pair of a data array and the index of next open value
// we will use index 0 as the root of the heap
typedef struct hp {
  int data[LIMIT];      // array to hold our heap data
  int next;             // index of next open slot in heap
} heap_t;


// note we will declare the max heap on our system stack - not w/malloc
// but we have to pass a pointer to the heap to most functions

// is the heap *h empty?
bool isEmpty(heap_t* h){
  if (h->next <= 0) {
    return(true);
  } else {
    return(false);
  }
}

// is the heap *h full?
bool isFull(heap_t* h){
  if (h->next >= LIMIT) {
    return(true);
  } else {
    return(false);
  }
}

// is the heap node of *h indexed by ix NULL?
// null nodes are beyond the frontier indexed by ix
bool isNull(heap_t* h, int ix){
  if (ix >= h->next) {
    return(true);
  } else {
    return(false);
  }
}

// finding parent, left, and right are independent of the heap *h
// they are entirely determined by the index relationships
// between parent, left child, and right child given the heap size

// find the index of the parent of node at index ix
int parent(int ix){
  // remember that the root has no parent, so just return 0
  if ((0 < ix) && (ix < LIMIT)) {
    return ((ix + 1) / 2) - 1;
  } else {
    return 0;
  }
}

// find the index of the left child of node at index ix
int leftChild(int ix){
  if ((0 <= ix) && (ix < LIMIT)) {
    return ((2 * ix) + 1);
  } else {
    return 0;
  }
}

// find the index of the right child of node at index ix
int rightChild(int ix){
  if ((0 <= ix) && (ix < LIMIT)) {
    return ((2 * ix) + 2);
  } else {
    return 0;
  }
}
  

// node at ix of heap *h may be out of place because it was just added
// trickle up through its chain of parents
void rebalanceUp(heap_t* h, int ix) {  
  if (ix == 0) {
    // ix is the root - we are done
  
  } else if ((0 < ix) && (ix < LIMIT) && (ix < h->next)) {
    // ix is a valid non-root node
    // see if value at ix is bigger than value of parent of ix
    // if so, then swap them and recurse
    if (h->data[parent(ix)] < h->data[ix]) {
      swap(&(h->data[parent(ix)]), &(h->data[ix]));
      rebalanceUp(h, parent(ix));
    }

  } else {
    // invalid node
    printf("***ERROR*** Attempting to rebalance node %d\n",ix);
  }

  return;
}

// node at ix of heap *h may be out of place because it was just added
// trickle down through its chain of children
void rebalanceDown(heap_t* h, int ix) {
  int left;
  int right;
  
  if ((0 <= ix) && (ix < LIMIT) && (ix < h->next)) {
    // ix is a valid node
    // see if value at ix is smaller than value of children of ix
    // if so, then swap them and recurse
    // note that if left child is null, then so is right child

    if (isNull(h, leftChild(ix))) {
      // both left and right children are NULL
      // this is a leaf node, so we are done
      
    } else if (isNull(h, rightChild(ix))) {
      // left child is not null, but right child is null
      // so we know left child is a leaf - has no children
      // should we swap with left child?
      left = leftChild(ix);
      if (h->data[left] > h->data[ix]) {
	swap(&(h->data[left]), &(h->data[ix]));
      }
      
    } else {
      // both children exist - find the largest
      left = leftChild(ix);
      right = rightChild(ix);
      if (h->data[left] > h->data[right]) {
	// left child is biggest - should we swap?
	if (h->data[left] > h->data[ix]) {
	  swap(&(h->data[left]), &(h->data[ix]));
	  rebalanceDown(h, left);
	}
      } else {
	// right child is biggest - should we swap
	if (h->data[right] > h->data[ix]) {
	  swap(&(h->data[right]), &(h->data[ix]));
	  rebalanceDown(h, right);
	}
      }
    }
  } else {
    // invalid node
    printf("***ERROR*** Attempting to rebalance node %d\n",ix);
   
  }
  return;
}

// initialize the heap *h to empty
void heapInit(heap_t* h){
  h->next = 0;
  return;
}

// push an integer d onto the heap *h
void push (heap_t* h, int d) { 
  if (isFull(h)) {
    // overflow of heap
    printf("***ERROR*** Cannot push data %d because heap is full\n", d);
  } else {
    // put d in the heap and increment the size of the heap
    h->data[h->next] = d;
    (h->next)++;

    // rebalance the new node by comparing to its parent
    rebalanceUp(h, (h->next)-1);
  }
  return;
}

// pop off the biggest value at the heap *h
int pop (heap_t* h) {
  int result;
  
  if (isEmpty(h)) {
    // underflow of heap
    printf("***ERROR*** Cannot pop because heap is empty\n");
    result = RAND_RANGE+1;
  } else {
    // get top of heap
    result = h->data[0];

    if (h->next <= 1) {
      // we just removed the last element of the heap
      h->next = 0;
    } else {
      // move the last element of the heap to the top and rebalance
      h->data[0] = h->data[h->next-1];
      (h->next)--;
      rebalanceDown(h, 0);
    }
  }
  return result;
}



// ========================== MAIN PROGRAM  ==========================
int main() {

  int source[MAX_INPUT]; // array to hold input data values
  int dest[MAX_INPUT];   // array to hold sorted data values

  int i;                 // loop variable
  int j;                 // loop variable

  heap_t heap;           // our heap
  heapInit(&heap);       // initialize to empty

  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize source array with random number from 0..RAND_RANGE
  for (i=0; i<MAX_INPUT; i++) {
    source[i] = rand() % RAND_RANGE;
  }

  // print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i=0; i < ((MAX_INPUT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < MAX_INPUT) {
	printf("%.2d ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");


  // push elements of source array into heap
  for (i=0; i<MAX_INPUT; i++) {
    push(&heap, source[i]);
  }

  // pop elements of heap into dest array
  for (i=0; i<MAX_INPUT; i++) {
    dest[i] = pop(&heap);
  }
  

  // print out destination array in rows of 20
  printf("Destination array:\n");
  for (i=0; i < ((MAX_INPUT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < MAX_INPUT) {
	printf("%.2d ",dest[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
