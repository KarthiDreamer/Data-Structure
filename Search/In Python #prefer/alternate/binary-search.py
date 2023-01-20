# Binary Search in python

array=[]
n=int(input("Enter Number of elements in the array: "))

print("Enter elemens one by one: ")

for i in range(n):
    e=int(input())
    array.append(e)
    
x=int(input("Enter element to Search: "))

def binarySearch(array, x, low, high):

    # Repeat until the pointers low and high meet each other
    while low <= high:

        mid = low + (high - low)//2

        if array[mid] == x:
            return mid

        elif array[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1


result = binarySearch(array, x, 0, len(array)-1)

if result != -1:
    print("Element is present at index " + str(result))
else:
    print("Not found")