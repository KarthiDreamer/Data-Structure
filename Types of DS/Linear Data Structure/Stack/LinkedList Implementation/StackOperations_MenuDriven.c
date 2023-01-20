#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

typedef struct Stack *STACK;

STACK top;

STACK create(int value)
{
    STACK newNode = malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// reverse linkedlist approach
// new node is created and value assigned, but newnode -> next = old node (not old node -> next = new node like linkedlist)
void push(){
        int val;
        printf("\nEnter value to push: ");
        scanf("%d", &val);

    if(top!=NULL){
        STACK temp  = create(val);
        temp->next = top;
        top = temp;
    }
    else{
        top = create(val);
    }
    printf("\nPushed %d", val);
}

void pop(){
    if(top!=NULL){
        // the address of current to is stored in temp(even after reassigning! linkedlist), then it is freed
        STACK temp = top;
        printf("\nPopped %d", temp->data);
        top = top->next;
        free(temp);
        
    }
    else{
        printf("\nStack is empty");
    }
}

void display(){
    if(top!=NULL){
        printf("\n\nDisplaying stack:");
        STACK temp = top;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    else{
        printf("\nStack is empty");
    }
}

void isStackEmpty(){
    if(top==NULL){
        printf("\nStack is empty");
    }
    else{
        printf("\nStack is not empty");
    }
}

void topMost(){
    if(top!=NULL){
        printf("\nTopmost element is %d", top->data);
    }
    else{
        printf("\nStack is empty");
    }
}


void main()
{
    top = malloc(sizeof(struct Stack));
    // make this NULL to avoid garbage value s->data = 0 and to go to else part of push()
    top = NULL;

    char c='y';

    while(c!='N'||c!='n'){

    int ch;
    printf("\nEnter array operation to perform:\n\n1.Push\n2.Pop\n3.Stack Empty Check\n4.Top Value\n5.Display stack");
    printf("\n\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch){
        
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        isStackEmpty();
        break;
    case 4:
        topMost();
        break;
    case 5:
        display();
        break;
    default:
        printf("Invalid Choice");

    }

    printf("\n\nDo you want to continue ? (y/N)");
    scanf("%s",&c);

    }

};
