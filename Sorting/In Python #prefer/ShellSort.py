#Shell Sort

# next level of insertion sort  //Larger swap, same methodology
# Note: double swap allowed for same variable

def shell(array,size):

    # find largest swap interval value in the array
    span=size//2
    
    while(span>0):
    
        for i in range(span,size):
            j=i
            # store a[i] in temporary varible and swap assign till possible
            temp=array[i]  
            # there is no point in the while loop if j<span LOL                                                     
            while(array[j-span]>temp and j>=span):                              
                array[j]=array[j-span]
                j-=span
                print("j=",j)

            # assign temp to the last swapp assigned position j
            array[j]=temp  
        # reduce swap interval to half slowly
        span=span//2
        
    return array
   
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
