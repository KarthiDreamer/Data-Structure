#include<stdio.h>
#include<stdlib.h>
#define Null 0

struct polynode {
int deg,coeff;
struct polynode *next;
};

typedef struct polynode* POLY;

void display(POLY l)
{
    if(l->next!=NULL)
        l=l->next;
    while(l!=NULL)
    {
        printf("%d %d|",l->deg,l->coeff);
        l=l->next;
    }
}

void insertlast(POLY l,int deg,int coeff)
{
    POLY temp=malloc(sizeof(struct polynode));
    while(l->next!=NULL)
        l=l->next;
    temp->deg=deg;
    temp->coeff=coeff;
    temp->next=NULL;
    l->next=temp;
    display(l);
}


POLY getPoly(int n){

    POLY T = (struct polynode*)malloc(sizeof(struct polynode)*n);
    POLY P=T;
    int val[100];

    P->deg=-1;
    P->coeff=-1;


    for(int i=0;i<n;i++){

        P=P->next;

        POLY temp = (struct polynode*)malloc(sizeof(struct polynode));
        printf("Enter coefficient of x power %d :",i);
        scanf("%d",&val[i]);

        temp->deg=val[i];
        temp->coeff=i;

    }

    return P;
}

POLY addpolynomial(POLY l1,POLY l2)
{
    POLY p=l1;
    POLY q=l2;
    POLY l3;
    while(p!=NULL&&q!=NULL)
    {
        if(p->deg==q->deg)
        {
            insertlast(l3,p->deg,p->coeff+q->coeff);
            p=p->next;
            q=q->next;
        }
        else if(p->deg>q->deg)
        {
            insertlast(l3,p->deg,p->coeff);
            p=p->next;
       }
       else
        {
            insertlast(l3,q->deg,q->coeff);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insertlast(l3,q->deg,q->coeff);
        p=p->next;

    }
    while(q!=NULL)
    {
        insertlast(l3,p->deg,p->coeff);
        q=q->next;
    }

    return l3;
}

int main(){
int c1,c2;

printf("Enter the degree of Polynomial 1:");
scanf("%d",&c1);
POLY p1=getPoly(c1+1);

printf("Enter the degree of Polynomial 2:");
scanf("%d",&c2);
POLY p2=getPoly(c2+1);

POLY p3=addpolynomial(p1,p2);
printf("control");
display(p3);

return 0;
}
