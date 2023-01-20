#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 30

int isbalanced(char str[], int len)
{
    char stack[MAXSIZE];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            stack[++top] = str[i];
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            
            if (top == -1)
            {
                return 0;
            }

            char c = stack[top--];
            if ((str[i] == ')' && c != '(') ||
                (str[i] == ']' && c != '[') ||
                (str[i] == '}' && c != '{')) 
            {
                return 0;
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

void main()
{

    char str[MAXSIZE];
    int l;
    printf("\nEnter the string with parenthesis:");
    scanf("%s", str);
    printf("\nEnter length of string");
    scanf("%d", &l);

    int r = isbalanced(str, l);

    if (r == 0)
        printf("\nThe parenthesis are not balanced");
    else
        printf("\nThe parenthesis are balanced");
}
