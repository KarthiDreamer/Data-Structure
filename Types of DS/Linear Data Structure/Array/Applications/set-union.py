def InputSet(array,n):
    for i in range(n):
        val = int(input())
        array.append(val)

def union(array1,array2):
    narray=[]
    for i in array1:
        narray.append(i)
    for j in array2:
        #lets assume that j won't be found in narray
        found=0
        for k in narray:
            if(j==k):
                #if found, do nothing
                found=1
                break
        #if not found add the new set value
        if(found==0):
            narray.append(j)
    print("The set union is:")
    for l in narray:
        print(l,end=" ")

array1 = []
array2 = []

n1=int(input("Enter number of elements in set1:"))
InputSet(array1,n1)
n2=int(input("Enter number of elements in set2:"))
InputSet(array2,n2)
union(array1,array2)


