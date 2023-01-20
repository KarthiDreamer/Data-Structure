//Selection Sort

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

    // debugging printf("\n");
}

void SelectionSort(int array[],int n){
    int min;
    int temp;
    for(int i=0;i<n;i++){
         min=i;
         for(int j=i;j<n;j++){
            if(array[j]<array[min]){
                min=j;
            }
         }

        temp=array[min];
        array[min]=array[i];
        array[i]=temp;

    }}

int main(){

    int n,array[50],key,r;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    getArray(array,n);

    printf("The given array is ");
    dispArray(array,n);
    SelectionSort(array,n);
    printf("\nThe Sorted array is ");
    dispArray(array,n);

}
