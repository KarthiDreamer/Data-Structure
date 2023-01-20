#include<stdio.h>

int insert(int array[],int ins,int n,int pos){
    for(int i=n;i>=pos-1;i--){
        array[i]=array[i-1];
            }
    array[pos-1]=ins;
    n++;
    return n;
}

int insertFirst(int array[],int ins,int n){
    for(int i=n;i>=0;i--){
        array[i]=array[i-1];
            }
    n++;
    array[0]=ins;

    return n;
}

int insertLast(int array[],int ins,int n){
    array[n]=ins;
    return n;
}

int delete(int array[],int n,int pos){
    for(int i=pos;i<n;i++){
        array[i-1]=array[i];
    }
    return n-1;
}

int deleteFirst(int array[],int n){
    for(int i=1;i<n;i++){
        array[i-1]=array[i];
    }
    return n-1;
}

int deleteLast(int array[],int n){
    
    return n-1;
}

void search(int array[],int n,int key){
    for(int i=0;i<n;i++){
        if(key==array[i]){
            printf("The value %d is found at index %d",key,i);
            return;
        }
    }
    printf("The value is not found");
}

//make n global

void main(){

    int array[100],n;
    int choice,key,ch1,ch2,pos,ins;
    char c='Y';
    
    printf("\nEnter number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter array values one by one: \n");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]); 
    }

    while(c=='Y'){

        printf("\nEnter array operation to perform\n\n1.Insert\n2.Delete\n3.Search");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to insert :");
                scanf("%d",&ins);
                printf("\nEnter the position of insert operation P\n\n1.Insert at first position\n2.Insert at last position\n3.Insert at given position\n");
                printf("Enter your choice: ");
                scanf("%d",&ch1);

                switch (ch1)
                {
                case 1:
                    n=insertFirst(array,ins,n);
                    break;
                case 2:
                    n=insertLast(array,ins,n);
                    break;
                case 3:
                    printf("Enter position to enter value :");
                    scanf("%d",&pos);
                    n=insert(array,ins,n,pos);
                    break;
                default:
                    printf("Invalid Input");
                    break;
                }
                break;
                
            case 2:
                printf("Enter the deletion operation\n1.Delete at first posiion\n2.Delete at last position\n3.Delete at given position");
                scanf("%d",&ch2);
                switch(ch2)
                {
                case 1:
                    n=deleteFirst(array,n);
                    break;
                case 2:
                    n=deleteLast(array,n);
                    break;
                case 3:
                    printf("Enter position to delete value :");
                    scanf("%d",&pos);
                    n=delete(array,n,pos);
                    break;
                default:
                    printf("Invalid Input");
                    break;
                }
                break;
                
            case 3:
                printf("Enter value to Search in the given array: ");
                scanf("%d",&key);
                search(array,n,key);
                break;
                
            default:
                printf("\nInvalid Input");
        }
        
            printf("The final array is: ");

        for(int i=0;i<n;i++){
            printf("%d",array[i]);
        }

        printf("\n\nDo you want to continue? (Y/N)\n");
        scanf("%s",&c);

        if(c!='Y'&& c!='N'){
            printf("\nInvalid Choice");
        }
    }

}
