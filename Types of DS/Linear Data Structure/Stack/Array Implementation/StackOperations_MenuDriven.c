#include<stdio.h>
#include<stdlib.h>

int top=-1;
int n;

void disp(int array[]){
    
    if(top>=0){
        printf("\nThe values in stack are \n");
        for(int i=top;i>=0;i--){
            printf("%d\t",array[i]);
        }
    }
    else{
        printf("The Stack is empty");
    }
    
}

void push(int array[]){

    if(top<n-1){
        int element;
        printf("\nEnter element to push: ");
        scanf("%d",&element);
        top++;
        array[top]=element;
        disp(array);
    }
    else{
        printf("\nThe Stack is Full");
    }
       
}

void pop(int array[]){

    if(top>-1){
        top--; 
    disp(array);

    }
    else{
        printf("\nThe Stack is Empty");
    }
    
}

void isStackEmpty(int array[]){

    if(top<0){
      printf("\nThe Stack is Empty ");  
    }
    else{
        printf("\nThe Stack is not Empty");
    }
    
}

void isStackFull(int array[]){

   if(top==(n-1)){
    printf("The Stack is Full ");
   }
   else{
    printf("The Stack is not Full ");
   }
    
}

void topMost(int array[]){

    if(top>-1){
       printf("The topmost element of stack is %d",array[top]); 
    }
    else{
        printf("\nThe Stack is Empty ");  
    }
    
}

void main(){
    
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    int *array=(int*)malloc(n*sizeof(int));
    
    char c='y';

    while(c=='y'||c=='Y'){

    int ch;
    printf("\nEnter array operation to perform:\n\n1.Push an element\n2.Pop an element\n3.Check if stack is empty\n4.Check if stack is full\n5.Return the topmost element of the stack\n6.Display stack elements");
    printf("\n\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch){
        
    case 1:
        push(array);
        break;
    case 2:
        pop(array);
        break;
    case 3:
        isStackEmpty(array);
        break;
    case 4:
        isStackFull(array);
        break;
    case 5:
        topMost(array);
        break;
    case 6:
        disp(array);
        break;
    default:
        printf("Invalid Choice");

    }

    printf("\n\nDo you want to continue ? (y/N)");
    scanf("%s",&c);

    }
    
}

