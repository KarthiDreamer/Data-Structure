#include <stdio.h>
#include <stdlib.h>
// #define NULL 0

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *NODE;

void insertFirst(NODE H, int ins)
{
    NODE temp =  malloc(sizeof(struct Node));
    temp->next = H->next;
    H->next = temp;
    temp->data = ins;
    printf("The value %d is successfully inserted",ins);
}

void insertLast(NODE H, int ins)
{
    NODE p = H;
    while (p->next != NULL)
    {
        p = p->next;
    }
    NODE temp =  malloc(sizeof(struct Node));
    temp->next = p->next;
    p->next = temp;
    temp->data = ins;
    printf("The value %d is successfully inserted",ins);
}

void insertAfter(NODE H, int ins, int key)
{
    NODE p = H;
    while (p->next != NULL && p->data != key)
    {
        p = p->next;
    }
    if (p->data == key)
    {
        NODE temp =  malloc(sizeof(struct Node));
        temp->next = p->next;
        p->next = temp;
        temp->data = ins;
    }
    else
    {
        printf("The given key value not found. ");
    }
    printf("The value %d is successfully inserted",ins);
}

void insertBefore(NODE H, int ins, int key)
{

    NODE p = H;
    while (p->next->next != NULL && p->next->data != key)
    {
        p = p->next;
    }
    if (p->next->data == key)
    {
        NODE temp =  malloc(sizeof(struct Node));
        temp->next = p->next;
        p->next = temp;
        temp->data = ins;
    }
    else
    {
        printf("\nThe given key value not found. \n");
    }
}

void deleteFirst(NODE H)
{

    NODE p = H->next;
    H->next = p->next;
    free(p);
}

void deleteLast(NODE H)
{

    NODE temp =  malloc(sizeof(struct Node));
    NODE p = H;
    while (p->next)
    {
        temp = p;
        p = p->next;
    }

    temp->next = NULL;
    free(p);
}

void deleteBefore(NODE H, int key)
{
    NODE p = H;
    NODE prev;
    while ((p->next->next != NULL) && (p->next->data != key))
    {
        prev = p;
        p = p->next;
    }
    if (p->next->data == key)
    {
        prev->next = p->next;
        free(p);
    }
    else
    {
        printf("The given key value not found. ");
    }
}

void deleteAfter(NODE H, int key)
{
    NODE p = H;

    while (p->next != NULL && p->data != key)
    {

        p = p->next;
    }
    if (p->data == key)
    {
        NODE temp;
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    else
    {
        printf("\nThe given key value not found. \n");
    }
}

void search(NODE H, int key)
{
    NODE p = H;
    int count = 0;
    while (p->next != NULL)
    {
        count++;
        if (p->data == key)
        {
            printf("The value is found at index %d \n", count);
            return;
        }

        p = p->next;
    }
    printf("The value is not found.");
}

void traverse(NODE H)
{
    NODE p = H;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void main()
{
    int choice, key, ch1, ch2, pos, ins, k,v;
    char c = 'Y';
    
    NODE N = malloc(sizeof(struct Node));
    N->next=NULL;

    while (c == 'Y')
    {

        printf("\nEnter the operation to perform\n\n1.Insert\n2.Delete\n3.Search");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the insert operation\n\n1.Insert at first position\n2.Insert at last position\n3.Insert before given value\n4.Insert after given value");
            printf("\nEnter your choice: ");
            scanf("%d", &ch1);

            printf("\nEnter the value to insert :");
            scanf("%d", &ins);

            switch (ch1)
            {

            case 1:
                insertFirst(N, ins);
                break;
            case 2:
                insertLast(N, ins);
                break;
            case 3:
                printf("Enter the position to insert after : ");
                scanf("%d", &k);
                insertAfter(N, ins, k);
                break;
            case 4:
                printf("Enter the position to insert before : ");
                scanf("%d", &k);
                insertBefore(N, ins, k);
                break;

            default:
                printf("Invalid Input");
            }
            break;

        case 2:
            printf("Enter the deletion operation\n1.Delete at first posiion\n2.Delete at last position\n3.Delete at given position");
            scanf("%d", &ch2);

            switch (ch2)
            {
            case 1:
                deleteFirst(N);
                break;
            case 2:
                deleteLast(N);
                break;
            case 3:
                printf("Enter the position to delete after : ");
                scanf("%d", &k);
                deleteAfter(N, k);
                break;
            case 4:
                printf("Enter the position to delete before : ");
                scanf("%d", &k);
                deleteBefore(N, k);
                break;

            default:
                printf("Invalid Input");
            }
            break;

        case 3:
            printf("Enter value to Search in the given LinkedList: ");
            scanf("%d", &key);
            search(N, key);
            break;

        default:
            printf("\nInvalid Input");
        }

        printf("\nThe final LinkedList is: ");
        traverse(N);

        printf("\n\nDo you want to continue? (Y/N)\n");
        scanf("%s", &c);

        if (c != 'Y' && c != 'N')
        {
            printf("\nInvalid Choice");
        }
    }
}
