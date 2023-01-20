#include<stdio.h>
#define size 7
#define Null 0

int front=-1,rear=-1;
int queue[size];

int isEmpty(){

    if( front==-1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if( (rear==size-1 && front==0) || (front == rear-1) ) {
        return 1;
    }
    else{
        return 0;
    }

}

void enqueue(int Q[]){
    if(isFull(Q)){
        printf("The queue is Full");
    }
    else{
    if (front == -1)
        front = 0;

    rear= rear%size+1;

    int val;
    printf("Enter the value to be inserted:");
    scanf("%d",&val);
    Q[rear]=val;
    printf("Succesfully Inserted value %d ",val);

    }
}

void dequeue(int Q[]){
    if(isEmpty(Q)){
        printf("The queue is Empty");
    }
    else{
        printf("Successfully Deleted value %d ",Q[front]);
        front = front%size+1;
        if(front > rear)
            front = rear = -1;
    }
}

void display(int Q[]){

     if(isEmpty(Q)){
        printf("\nThe queue is Empty");
    }else{
        printf("\nThe values in queue are :");
        for(int i=front;i<=rear;i++){
            printf("\n%d",Q[i]);
        }
    }

}

void peek(int Q[]){
     if(isEmpty(Q)){
        printf("The queue is Empty");
    }
    else{
        printf("The first value is %d",Q[front]);
    }

}

void main(){

    int c;
    char ch;

    do {
    printf("\nEnter the Queue operation to perform:");
    printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.display");
    printf("\nEnter your choice:");
    scanf("%d",&c);
       switch (c)
    {
    case 1:
        enqueue(queue);
        break;
    case 2:
        dequeue(queue);
        break;
    case 3:
        peek(queue);
        break;
    case 4:
        display(queue);
        break;
    default:
        printf("\nInvalid value");
        break;
    }

    printf("\n\nDo you want to continue? (y/N)");
    scanf("%s",&ch);

    }while(ch=='y'|| ch=='Y');

}
