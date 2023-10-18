# the step of combining sorted subarrays tgt
def merge(left_sorted_array, right_sorted_array):
    p1, p2 = 0, 0
    merged_array = []

    # combining 2 sorted arrays into 1
    while (p1 < len(left_sorted_array) and p2 < len(right_sorted_array)):
        if left_sorted_array[p1] < right_sorted_array[p2]:
            merged_array.append(left_sorted_array[p1])
            p1 += 1
        else:
            merged_array.append(right_sorted_array[p2])
            p2 += 1
    
    # if there's anything left in either array
    merged_array.extend(left_sorted_array[p1:])
    merged_array.extend(right_sorted_array[p2:])
    return merged_array

def mergesort(array):
    if len(array) <= 1:
        return array

    # sort subarrays
    mid = len(array) // 2
    left_sorted_array = mergesort(array[:mid])
    right_sorted_array = mergesort(array[mid:])

    # merge left & right sorted arrays
    return merge(left_sorted_array, right_sorted_array)


if __name__ == "__main__":
    array = [12, 11, 13, 5, 6, 7]
    print("unsorted array:")
    print(array)

    sorted_array = mergesort(array)
    print("sorted array:")
    print(sorted_array)