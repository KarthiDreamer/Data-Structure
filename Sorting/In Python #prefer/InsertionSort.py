#Insertion Sort

def insertion(array,size):

    for i in range(1,size):
        key=array[i]
        j=i-1                                      #1st left element from key

        while(key < array[j] and j>=0):            #traverse and compare left element untill the the greater value is found or end is reached
                array[j+1]=array[j]
                j=j-1
        
        array[j+1]=key                             #assign the key value in the front (of an imaginary sorted array)


def getList(array,n):
    for i in range(n):
        print("Enter value {} :".format(i+1))
        val=int(input())
        array.append(val)

n=int(input("\nEnter the number of elements in the list:"))

print("\nEnter the list elements:")
array=[]
getList(array,n)

print("\nThe sorted array is ")
print(array)