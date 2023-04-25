def heapify(arr, N, i):
    largest = i # initialize largest as root
    left = 2*i + 1
    right = 2*i + 2
    
    # if child exists and is greater than largest, mark it as largest
    if left < N and arr[left] > arr[largest]:
        largest = left
    if right < N and arr[right] > arr[largest]:
        largest = right

    # swap root with largest if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        # heapify the root
        heapify(arr, N, largest)


def heap_sort(arr):
    N = len(arr)
    # build a max heap
    for i in range(N//2 -1, -1, -1):
        heapify(arr, N, i)


if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    heap_sort(arr)
    N = len(arr)

    print("sorted array: ")
    for i in range(N):
        print("%d" % arr[i], end=" ")