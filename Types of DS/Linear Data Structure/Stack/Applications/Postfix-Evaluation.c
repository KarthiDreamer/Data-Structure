#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 50

struct Stack
{
    int data;
    struct Stack* next;
};

typedef struct Stack* stack;

stack top = NULL;

stack createNode(int val)
{
    stack newNode = malloc(sizeof(struct Stack));
    newNode->data = val;
    newNode->next = NULL;
}

void push(int val)
{
    stack temp=createNode(val);
    if(top==NULL)
        top = temp;
    else
        temp->next=top;
    top = temp;
}

char pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow");
        return NULL;
    }
    else
    {
        int c = top->data;
        top=top->next;
        return c;
    }
}

int postEval(char* postfix)
{
    for(int i=0; i<strlen(postfix); i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch(postfix[i])
            {
            case '+':
                push(val2+val1);
                break;
            case '-':
                push(val2-val1);
                break;
            case '*':
                push(val2*val1);
                break;
            case '/':
                push(val2/val1);
                break;
            default:
                printf("Invalid Symbol detected");
            }

        }
    }
    return pop();

}

void main()
{
    char postfix[maxsize];
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    int eval = postEval(postfix);
    if(eval==-1)
    {
        printf("\nThe expression couldn't be evaluated");
    }
    else
    {
        printf("\nThe evaluated value is :\n%d",eval);
    }
}

/*
why we push (postfix[i]-'0' ) instead  of push(postfix[i]) only in the if part of postEval function

In the if part of the postEval function, postfix[i] is a character, representing a digit of the expression. However, if you want to perform arithmetic operation on it, you need to convert it to an int type.

postfix[i] - '0' is used to convert the ascii value of the digit character to its corresponding int value.

For example, the ascii value of the digit '1' is 49, but the int value of the digit is 1. So by doing this '0' is being subtracted to get the real digit value
It's the same reason that when we use isdigit(postfix[i]), it checks the ascii value of the character to check if it is a digit or not
*/
