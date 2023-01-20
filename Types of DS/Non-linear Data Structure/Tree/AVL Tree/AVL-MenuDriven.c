#include <stdio.h>
#include <stdlib.h>

//https://www.geeksforgeeks.org/insertion-in-an-avl-tree/

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct Node *NODE;


NODE a;

// RL = LL + RR , LR = RR + LL

NODE create(int value){
    NODE t = malloc(sizeof(struct Node));
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    t->height = 0;
    return t;
}

int height(NODE t){
    if(t==NULL){
        return -1;
    }
    else{
        return t->height;
    }
}

int max(NODE a,NODE b){
    return (a->height>b->height)?a->height:b->height;
}

int getBalance(NODE n){
    if(n=NULL)
        return 0;
    return height(n->left) - height(n->right);
}

NODE LeftRotate(NODE z){
    
    NODE y = z->right;
    NODE T2 = y->left;

    y->left = z;
    z->right = T2;

    y->height = max(y->left,y->right)+1;
    z->height = max(z->left,z->right)+1;

    return y;
}

NODE RightRotate(NODE z){
    NODE y = z->left;
    NODE T2 = y->right;

    y->right = z;
    z->left = T2;

    y->height = max(y->left,y->right)+1;
    z->height = max(z->left,z->right)+1;

    return y;
}

NODE newNode(int key){

    NODE temp = malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

void preOrder(NODE root){
    if(a!=NULL){
        printf("\nPre order traversal of AVL tree:");
        while (a!=NULL)
        {
            printf("%d ",root->data);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
}

NODE insert(NODE a,int val){

    if(a==NULL){
        return newNode(val);
    }
    else if(val < a->data){
        a->left = insert(a->left,val);
    }
    else if (val > a->data)
    {
        a->right = insert(a->right,val);
    }
    else{
        return a;
    }

    int bal = getBalance(a);

    if(bal > 1 && val < a->left->data){
        return LeftRotate(a);
    }
    if(bal > 1 && val > a->left->data){
        a->left=RightRotate(a->left);
        return LeftRotate(a);
    }
    if(bal < -1 && val > a->right->data){
        return RightRotate(a);
    }   
    if(bal < -1 && val < a->right->data ){
        a->right = LeftRotate(a->right);
        return RightRotate(a);
    }
    
    return a;
    
}

void main(){
    a = malloc(sizeof(struct Node));
    // make this NULL to avoid garbage value s->data = 0 and to go to else part of push()
    a = NULL;

    char c='y';

    while(c!='N'||c!='n'){

    int ch,val;
    printf("\nEnter array operation to perform:\n\n1.Insert\n2.Display");
    printf("\n\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch){
        
    case 1:
        printf("Enter value to insert:");
        scanf("%d",&val);
        a=insert(a,val);
        break;
    case 2:
        if(a!=NULL)
            preOrder(a);
        else
            printf("\nNo nodes are present in the tree");
        break;
    default:
        printf("\nInvalid Choice");

    }

    printf("\n\nDo you want to continue ? (y/N)");
    scanf("%s",&c);

    }

}



