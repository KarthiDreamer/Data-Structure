#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 30

char stack[30];
int top = -1;
char postfix[30];
int pl=0;

int Prec(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

void push(char c)
{
    stack[++top]=c;
}

int pop()
{
    if(top!=-1)
        return stack[top--];
    else
        printf("\nStack is empty");
    return -1;
}

int peek()
{
    if(top!=-1)
        return stack[top];
    else
        printf("Stack is empty");
    return -1;
}

int isOperand(char c)
{
    if ((c >= 'a' && c >= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int isEmpty(){
    return (top==-1)?1:0;
}

void infixToPostfix(char *infix)
{
    if(infix==NULL){
        printf("\nEmpty String!");
    }
    for (int i = 0; i < strlen(infix); i++)
    {
        if (isOperand(infix[i])){
            postfix[++pl]=infix[i];
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                postfix[++pl] = pop();
            }
            if(stack[top] != '(' && top != -1){
                printf("Invalid Expression");
            }
            else{
                pop();
            }
        }
        else 
        {
            while (!isEmpty(stack) && (Prec(infix[i]) <= Prec(peek(stack)) && Prec(infix[i])!=3 ))
            {
                infix[++pl] = pop(stack);
            }
            push(infix[i]);
            
        }
    }

    while (!isEmpty())
        postfix[++pl]=pop();

    postfix[++pl]='\0';

    printf("\nThe postfix expression is:\n%s",postfix);

    
}

void main()
{
    char infix[50];
    printf("\nEnter the infix expression:");
    scanf("%s", infix);
    infixToPostfix(infix);
}