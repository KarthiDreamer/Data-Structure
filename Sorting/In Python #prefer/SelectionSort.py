# Selection sort in Python

def selectionSort(array, size):
   
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
         
            # to sort in descending order, change > to < in this line
            # select the minimum element in each loop
            if array[i] < array[min_idx]:
                min_idx = i
         
        # put min at the correct position
        (array [step], array[min_idx]) = (array[min_idx], array[step])

def getList(array,n):
    for i in range(n):
        print("Enter value {} :".format(i+1))
        val=int(input())
        array.append(val)

n=int(input("\nEnter the number of elements in the list:"))

print("\nEnter the list elements:")
array=[]
getList(array,n)

selectionSort(array,n)

print('Sorted Array in Ascending Order:')
print(array)