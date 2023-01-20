#include<stdio.h>
#include<stdlib.h>
#define Null 0

struct polynode
{
int deg,coeff;
struct polynode*next;
};

typedef struct polynode*Plist;

Plist create(){
Plist P=malloc(sizeof(struct polynode));
P->coeff=0;
P->next=Null;
P->deg=Null;
return P;
}

Plist insertlast(Plist P,int d,int x){
Plist l=P;
while(l->next!=Null)
l=l->next;
Plist temp=malloc(sizeof(struct polynode));
temp->coeff=x;
temp->deg=d;
temp->next=l->next;
l->next=temp;
return l;
}

void display(Plist P){
Plist l=P->next;
if(P->next!=Null){
l=P->next;
while(l!=Null){
printf("Degree:%d\t",l->deg);
printf("Coefficient:%d\n",l->coeff);
l=l->next;
}
}
}

void duplication(Plist R){

Plist r=R;
Plist dup;
while(r!=Null && r->next!=Null){
Plist q=r;

while(q->next!=Null){

if(r->deg == q->next->deg){
r->coeff=r->coeff+q->next->coeff;
dup=q->next;
q->next=q->next->next;
free(dup);
}
else
q=q->next;

}

r=r->next;
}

}


Plist Multipoly(Plist P,Plist Q,Plist R){

Plist p1=P;
Plist p2=Q;
while(p1!=Null){

while(p2!=Null){

int deg,coeff;
deg=p1->deg+p2->deg;
coeff=p1->coeff*p2->coeff;
insertlast(R,deg,coeff);
p2=p2->next;

}

p2=Q;
p1=p1->next;
}

duplication(R);
return R;

}

int main(){
Plist P;
Plist Q;
Plist R;
P=create();
Q=create();
R=create();
int n,x,ch,s,d,y,k;
printf("Enter the no of elements for polynomial 1:");
scanf("%d",&n);
printf("Enter the elements of polynomial 1\n");
for(int i=0;i<n;i++){
printf("Enter The Degree of %d node:",i+1);
scanf("%d",&d);
printf("Enter its coefficient:");
scanf("%d",&x);
insertlast(P,d,x);
}
printf("Enter the no of elements for polynomial 2:");
scanf("%d",&n);
printf("Enter the elements of polynomial 2\n");
for(int i=0;i<n;i++){
printf("Enter The Degree of %d node:",i+1);
scanf("%d",&d);
printf("Enter its coefficient:");
scanf("%d",&x);
insertlast(Q,d,x);
}
printf("Polynomial 1:\n");
display(P);
printf("Polynomial 2:\n");
display(Q);
printf("Resultant Polynomial:\n");
Multipoly(P,Q,R);
display(R);
}

