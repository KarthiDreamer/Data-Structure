def merge(left_half, right_half):
    i = 0
    j = 0
    k = 0
    
    result = [0]*(len(left_half) + len(right_half))
    while i < len(left_half) and j < len(right_half):
        if left_half[i] < right_half[j]:
            result[k] = left_half[i]
            i += 1
        else:
            result[k] = right_half[j]
            j += 1
        k += 1
    while i < len(left_half):
        result[k] = left_half[i]
        i += 1
        k += 1
    while j < len(right_half):
        result[k] = right_half[j]
        j += 1
        k += 1
    return result


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left_half = arr[:mid]
        right_half = arr[mid:]

        left_half = merge_sort(left_half)
        right_half = merge_sort(right_half)

        arr = merge(left_half, right_half)
    return arr

arr = [38, 27, 43, 3, 9, 82, 10]
print("Sorted Array: ", merge_sort(arr))
