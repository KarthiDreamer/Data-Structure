#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

int isEmpty(){
    if(front == NULL)
        return 1;
    return 0;
}

void enqueue(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    //if it is the first node
    if(front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        //add newnode in rear->next
        rear->next = newNode;

        //make the new node as the rear node
        rear = newNode;
    }
}

void dequeue()
{
    //used to free the first node after dequeue
    struct node *temp;

    if(isEmpty())
         printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        //take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;

        //if front == NULL, set rear = NULL
        if(front == NULL)
            rear = NULL;

       //free the first node
       free(temp);
    }

}

void printList()
{
    struct node *temp = front;

    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void peek()
{
    if(isEmpty()){
        printf("The Queue is Empty.");
    }
    else{
        printf("The front value of queue is %d",front->data);
    }

}


void main(){

    int c;
    char ch;
    int val;

    do {
    printf("\nEnter the Queue operation to perform:");
    printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.display");
    printf("\nEnter your choice:");
    scanf("%d",&c);

       switch (c)
    {
    case 1:
        printf("Enter value to Enqueue:");
        scanf("%d",&val);
        enqueue(val);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        peek();
        break;
    case 4:
        printList();
        break;

    default:
        printf("\nInvalid value");
        break;
    }

    printf("\n\nDo you want to continue? (y/N)");
    scanf("%s",&ch);

    }while(ch=='y'|| ch=='Y');

}
