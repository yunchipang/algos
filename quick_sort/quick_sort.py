# function to find the partition position
# return the index of the pivot
def partition(array, left, right):

    # choose the rightmost element as pivot (can be done differently)
    pivot = array[right]

    # pointer for greater element
    # view this pointer as the leftmost index of elements greater than pivot
    # so before returning, swap(array[greaterElemIndex], array[right]) to move pivot to its rightful position
    firstGreaterElemIndex = left

    # traverse through all elements and compare themw ith pivot
    # if element <= pivot, swap it with the element at current "greaterElemIndex"
    for i in range(left, right):
        if array[i] <= pivot:
            array[i], array[firstGreaterElemIndex] = array[firstGreaterElemIndex], array[i]
            firstGreaterElemIndex += 1
    
    # swap the pivot element with the element at greaterElemIndex
    array[firstGreaterElemIndex], array[right] = array[right], array[firstGreaterElemIndex]
    return firstGreaterElemIndex

def quicksort(array, left, right):
    if left < right:
        pivotIndex = partition(array, left, right)
        # recursive call on the left of pivot (sort the portion which is less than pivot)
        quicksort(array, left, pivotIndex-1)
        # recursive call on the right of pivot (sort the portion which is greater than pivot)
        quicksort(array, pivotIndex+1, right)


if __name__ == "__main__":
    array = [1, 7, 4, 1, 10, 9, -2]
    print("unsorted array: ")
    print(array)

    quicksort(array, 0, len(array)-1)
    print("sorted array: ")
    print(array)
