# Bubble sort in Python
# sinking sort

def bubbleSort(array):
  # loop to access each array element
  for i in range(len(array)):
    # loop to compare array elements
    for j in range(0, len(array) - i - 1):
      # compare two adjacent elements
      # change > to < to sort in descending order
      if array[j] > array[j + 1]:
        # swapping elements if elements
        # are not in the intended order
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp

def getList(array,n):
    for i in range(n):
        print("Enter value {} :".format(i+1))
        val=int(input())
        array.append(val)

n=int(input("\nEnter the number of elements in the list:"))

print("\nEnter the list elements:")
array=[]
getList(array,n)

bubbleSort(array)

print('Sorted Array in Ascending Order:')
print(array)