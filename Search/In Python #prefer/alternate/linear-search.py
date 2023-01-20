# Linear Search 

array=[]
n=int(input("Enter Number of elements in the array: "))

print("Enter elemens one by one: ")

for i in range(n):
    e=int(input())
    array.append(e)
    
x=int(input("Enter element to Search: "))

def linearSearch(array,n,x):

    # Going through array sequencially
    for i in range(0, n):
        if (array[i] == x):
            return i
    return "N"

result = linearSearch(array, n, x)
if(result == "N"):
    print("Element not found")
else:
    print("Element found at index: ", result)