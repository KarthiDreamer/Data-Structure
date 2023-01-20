#include<stdio.h>
#include<stdlib.h>

void getArray(int array[],int n){

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("\n");
}

void dispArray(int array[],int n){

    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }  

    printf("\n") ; //debug
}

void merge(int array[],int low,int mid,int high){
    
    int n1=mid-low+1;                               // watch out
    int n2=high-mid;
    int* array1=(int*)malloc(sizeof(int*)*n1);
    int* array2=(int*)malloc(sizeof(int*)*n2);

    for(int i=0;i<n1;i++){
        array1[i]=array[low+i];
    }

    for(int j=0;j<n2;j++){
        array2[j]=array[mid+1+j];
    }

    int i=0,j=0,k=low;

    while(i<n1 && j<n2){
        if(array1[i]<array2[j]){
            array[k]=array1[i];
            i++;
        }
        else{
            array[k]=array2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
         array[k]=array1[i];
            i++;
            k++;
            
    }

    while(j<n2){
        array[k]=array2[j];
            j++;
            k++;     

    }

}

void MergeSort(int array[],int low,int high){
   
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(array,low,mid);
        MergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }

    }

int main(){

    int n,array[50],key,r;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    getArray(array,n);

    printf("The given array is array is ");
    dispArray(array,n);
    MergeSort(array,0,n-1);
    printf("\nThe Sorted array is array is ");
    dispArray(array,n);

}
