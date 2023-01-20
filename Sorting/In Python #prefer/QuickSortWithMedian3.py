# Quick Sort with Median 3 using Python

# https://youtu.be/PgBzjlCcFvc also see the comment for median3

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def median3(array,leftInd,rightInd):

    mid = (leftInd+rightInd) // 2

    if(array[leftInd]>array[mid]):
        swap(array,leftInd,mid)
    if(array[mid]>array[rightInd]):
        swap(array,mid,rightInd)
    if(array[leftInd]>array[rightInd]):
        swap(array,leftInd,rightInd)

    swap(mid,rightInd)
    return array[rightInd]


def partition(array, leftInd, rightInd):

    pivot = median3(array,leftInd,rightInd)
    i = leftInd-1

    for j in range(leftInd,rightInd):
        if(array[j]<=pivot):
            i=i+1
            swap(array,i,j)
        
    # move the pivot to the place where left elements are small 
    # and right elements are large (i.e after i value), rightInd is the pivot

    swap(array,i+1,rightInd)
    return i+1


def quicksort(array, leftindex, rightindex):

    #left and right must not be equal , ie length 1 not allowed
    if leftindex < rightindex:
        newpivotindex = partition(array, leftindex, rightindex)
        quicksort(array, leftindex, newpivotindex-1)
        quicksort(array, newpivotindex + 1, rightindex)


def getList(array,n):
    for i in range(n):
        val=int(input())
        array.append(val)


n=int(input("\nEnter the number of elements in the list:"))

print("\nEnter the list elements:")
array=[]
getList(array,n)

quicksort(array,0,n-1)

print("\nThe sorted array is ")
print(array)