#include<stdio.h>

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

void ShellSort(int array[],int n){
    int temp=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=(n-1-i);j++){
                if(array[j-1]>array[j]){
                    temp=array[j];
                    array[j]=array[j-1];
                    array[j-1]=temp;
                }
            }
            printf("%s",array);
        }
    }

int main(){

    int n,array[50],key,r;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    getArray(array,n);

    printf("The given array is array is ");
    dispArray(array,n);
    ShellSort(array,n);
    printf("\nThe Sorted array is array is ");
    dispArray(array,n);

}
