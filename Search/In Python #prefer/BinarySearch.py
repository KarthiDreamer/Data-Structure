#Binaryrayr Searrayrch in Python

def BinarySearch(array,low,heigh,k):
    if(low<=heigh):
        mid=(low+heigh)//2
        #here the fraction part is skipped , so mid = mid-1(even list) or real mid(odd list)
        
        if(k==array[mid]):
            print("The value {} is found at index {}".format(k,mid))
            return
        elif(k<array[mid]):
            #go before mid and search the subarray
            BinarySearch(array,low,mid-1,k)
        else:
            #go after mid 
            BinarySearch(array,mid+1,heigh,k)
    else:
        print("The value not found")
    

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
low = 0
heigh = n-1
BinarySearch(array,low,heigh,k)




