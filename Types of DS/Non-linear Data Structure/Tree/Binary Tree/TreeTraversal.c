// Binary Tree Traversal 
// Output is commented below

#include<stdio.h>
#include<stdlib.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree *TREE;

// left root right recursive call
void inorder(TREE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ->",root->data);
        inorder(root->right);
    }
}

// root left right recursive call
void preorder(TREE root){
    if(root!=NULL){
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// left right root recursive call
void postorder(TREE root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ->",root->data);
    }
}

TREE create(int value){
    TREE t = malloc(sizeof(struct Tree));
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insertLeft(TREE root,int value){
    root->left = create(value);
}

void insertRight(TREE root,int value){
    root->right = create(value);
}

TREE moveleft(TREE root){
    if(root->left!=NULL){
        printf("Moving to Left node succeeded");
        root=root->left;
        return root;
    }
    else{
        printf("No node is present in the left");
    } 
}

TREE moveright(TREE root){
    if(root->right!=NULL){
        printf("Moving to Right node succeeded");
        root=root->right;
        return root;
    }
    else{
        printf("No node is present in the right");
    }
}

int main(){

    int ins=0;
    char c='y';
    int n;
    int ch;

    //mroot is the main root , used for traversal only
    TREE mroot = create(-1);

    //root is a copy for operations and to control current node
    TREE root = mroot;

    do{
        printf("\nEnter the operation to perform ");
        printf("\n1.Insert Left\n2.Insert Right\n3.Move Left\n4.Move Right\n5.InOrder Traversal\n6.PreOrder Traversal\n7.PostOrder Traversal\n\nEnter Your Choice:");
        scanf("%d",&ch);

        switch (ch)
        {

        case 1:
            printf("Enter the value to Insert in the left:");
            scanf("%d",&ins);
            insertLeft(root,ins);
            break;

        case 2:
            printf("Enter the value to Insert in the right:");
            scanf("%d",&ins);
            insertRight(root,ins);
            break;

        case 3:
            root=moveleft(root);
            break;

        case 4: 
            root=moveright(root);
            break;

        case 5:
            inorder(mroot);
            printf(" NULL");
            break;

        case 6:
            preorder(mroot);
            printf(" NULL");
            break;

        case 7:
            postorder(mroot);
            printf(" NULL");
            break;
        
        default:
            printf("\nInvalid Input");
            break;
        }

        printf("\nDo you want to continue?(y/N)");
        scanf("%s",&c);
    }while(c=='y'||c=='Y');

    return 0;
}

/*
Output:

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:1
Enter the value to Insert in the left:1

Do you want to continue?(y/N)y

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:2
Enter the value to Insert in the right:2

Do you want to continue?(y/N)y

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:3
Moving to Left node succeeded
Do you want to continue?(y/N)y

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:1
Enter the value to Insert in the left:3

Do you want to continue?(y/N)y

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:2
Enter the value to Insert in the right:4

Do you want to continue?(y/N)y

Enter the operation to perform 
1.Insert Left
2.Insert Right
3.Move Left
4.Move Right
5.InOrder Traversal
6.PreOrder Traversal
7.PostOrder Traversal

Enter Your Choice:5
3 ->1 ->4 ->-1 ->2 -> NULL
Do you want to continue?(y/N)

*/