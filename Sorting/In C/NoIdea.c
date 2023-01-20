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

void SelectioSort(int array[],int n){
    int temp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<=(n-1-i);j++){
                if(array[j-1]>array[j]){
                    temp=array[j];
                    array[j]=array[j-1];
                    array[j-1]=temp;
                }
            }
        }
    }

int main(){

    int n,array[50],key,r;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    getArray(array,n);

    printf("The given array is ");
    dispArray(array,n);
    SelectioSort(array,n);
    printf("\nThe Sorted array is ");
    dispArray(array,n);

}
