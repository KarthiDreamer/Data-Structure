#include<stdio.h>
#include<conio.h>

void getArray(int array[],int n){

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
}

void dispArray(int array[],int n){

    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }   
}

int BinarySearch(int array[],int key,int low,int high){
    int mid=(low+high)/2;
    while(mid){
        if(array[mid]==key)
            return mid;
        else if(key<array[mid])
            return BinarySearch(array,key,low,mid-1);
        else    
            return BinarySearch(array,key,mid+1,high);
    }
    return -1;
    }

int main(){

    int n,array[50],key,r;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    getArray(array,n);

    printf("Enter element to search: ");
    scanf("%d",&key,n);

    
    printf("The given array is ");
    dispArray(array,n);
    r=BinarySearch(array,key,0,n-1);

    if(r!=-1)
        printf("\nThe element %d is found at index %d",key,r);
    else
        printf("\nThe element is not found");

}
