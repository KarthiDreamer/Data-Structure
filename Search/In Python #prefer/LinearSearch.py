#Linear Search in Python

def linearSearch(array,n,k):
    for i in range(n):
        if(array[i]==k):
            print("The value {} is found at index {}".format(k,i))
            return
    print("Value not found")
    

def getList(array,n):
    for i in range(n):
        print("Enter value {} :".format(i+1))   
        val=int(input())
        array.append(val)

n=int(input("\nEnter the number of elements in the list:"))

print("\nEnter the list elements:")
array=[]
getList(array,n)

k=int(input("\nEnter value to search:"))

linearSearch(array,n,k)




