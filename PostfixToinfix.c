#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101
char stack[MAX];
int top = -1;
void Push(int data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    stack[++top] = data;
}
void Pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    top--;
}
int isOperand(int ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PostfixToInfix(char Postfix[])
{
    char ch;
    int i = 0, j = 0;
    while (i < strlen(Postfix))
    {
        ch = Postfix[i];
        if (isOperand(ch))
        {
            Push(ch);
            Push(' ');
        }
        else
        {
            for (j = top - 1; j >= 0; j--)
            {
                if (stack[j] == ' ')
                {
                    stack[j] = ch;
                    break;
                }
            }
        }
        i++;
    }
    printf("Infix expression= %s", stack);
}
int main()
{
    char Postfix[MAX];
    printf("Enter postfix expression: ");
    gets(Postfix);
    PostfixToInfix(Postfix);
    return 0;
}
