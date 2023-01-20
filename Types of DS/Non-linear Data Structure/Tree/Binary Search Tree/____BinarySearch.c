// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree *TREE;

TREE create(int value)
{
    TREE t = malloc(sizeof(struct tree));
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insert(TREE root, int val)
{

    if (root != NULL)
    {

        if (val <= root->data)
        {
            if (root->left == NULL)
            {
                root->left = create(val);
            }
            else
            {
                insert(root->left, val);
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = create(val);
            }
            else
            {
                insert(root->right, val);
            }
        }
    }
}

//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

void delete(TREE root, int val)
{
    if(root!=NULL){
        if(val < root->left->data){
            delete(root->left,val);
        }
        else if (val > root->right->data)
        {
            delete(root->right,val);
        }
        else 
        {
            if(root->left==NULL && root->right==NULL){
                free(root);
            }
            else if(root->left==NULL){
                TREE temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->right==NULL){
                TREE temp = root;
                root = root->left;
                free(temp);
            }
            else{
                TREE temp = root->right;
                while(temp->left!=NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                delete(root->right,temp->data);
            }
        }  
    }
    
}

int search(TREE root, int val)
{
    if (root != NULL)
    {
        if (val == root->data)
        {
            return 1;
        }
        else if (val > root->data)
        {
            search(root->right, val);
        }
        else
        {
            search(root->left, val);
        }
    }
}

// left root right recursive call
void inorder(TREE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ->", root->data);
        inorder(root->right);
    }
}

int main()
{
    int val;
    char c = 'y';
    int ch;

    // mroot is the main root , used for traversal only
    TREE mroot = create(-1);

    // root is a copy for operations and to control current node
    TREE root = mroot;

    do
    {
        printf("\nEnter the operation to perform ");
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter value to insert");
            scanf("%d", &val);
            insert(root, val);
            break;

        case 2:
            printf("Enter value to delete");
            scanf("%d", &val);
            delete (root, val);
            break;

        case 3:
            printf("Enter value to search");
            scanf("%d", &val);
            int result = search(mroot, val);
            if(result==1)
                printf("The value is found in the binary tree!");
            else
                printf("The value not found");
            break;

        case 4:
            inorder(mroot);
            printf("NULL");
            break;

        default:
            printf("\nInvalid Input");
            break;
        }

        printf("\nDo you want to continue?(y/N)");
        scanf("%s", &c);

    } while (c == 'y' || c == 'Y');
}