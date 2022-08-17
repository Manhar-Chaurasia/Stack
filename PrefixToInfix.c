#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        return;
    }
    top--;
}
int isOperand(char ch)
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
void PrefixToinfix(char Prefix[])
{
    char ch;
    int i;
    i = strlen(Prefix) - 1;
    while (i >= 0)
    {
        ch = Prefix[i];
        if (isOperand(ch))
        {
            Push(ch);
            Push(' ');
        }
        else
        {
            for (int j = top - 1; j >= 0; j--)
            {
                if (stack[j] == ' ')
                {
                    stack[j] = ch;
                    break;
                }
            }
        }
        i--;
    }
    printf("Infix expression= %s", strrev(stack));
}
int main()
{
    char Prefix[MAX];
    printf("Enter prefix expression: ");
    gets(Prefix);
    PrefixToinfix(Prefix);
    return 0;
}
