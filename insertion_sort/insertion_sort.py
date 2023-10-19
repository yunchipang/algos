'''
中心思想：每輪都面對一個新的item
嘗試在這個item左邊的sorted portion找到正確的位置插入這個物件
'''
def insertsion_sort(array):
    N = len(array)

    # edge case
    if N <= 1:
        return array
    
    for i in range(1, N): # iterate through the array starting from the second index
        currentItem = array[i] # current item to be inserted

        j = i-1
        # find the correct position to insert current item
        while j >= 0 and currentItem < array[j]:
            # if current item is smaller than the last item in the sorted portion
            # need to find a place in sorted portion to insert current item
            array[j+1] = array[j] # 把j位置的東西往右搬一格 想像空出位置給等等要插入的current item
            # shift j pointer to the left
            j -= 1

        # insert currentItem to the right of j
        array[j+1] = currentItem
    

if __name__ == "__main__":
    array = [2, 25, 10, 45, 1]
    print("unsorted array:")
    print(array)

    insertsion_sort(array)
    print("sorted array:")
    print(array)