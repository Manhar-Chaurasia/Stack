#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top = -1;
void Push(int data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
    }
    stack[++top] = data;
}
int Pop()
{
    int d;
    if (top == -1)
    {
        printf("Underflow\n");
    }
    d = stack[top--];
    return d;
}

int Precedence(char symbol)
{
    if (symbol == '^')
    {
        return 4;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 3;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 2;
    }
    else if (')')
    {
        return 1;
    }
    else if (symbol == '#')
    {
        return 0;
    }
}

void InfixToPrefix(char Infix[], char Prefix[])
{
    int i = 0, k = 0;
    char ch, x;
    Push('#');
    strrev(Infix); // reversing infix expression
    while ((ch = Infix[i++]) != '\0')
    {
        if (ch == ')')
        {
            Push(ch);
        }
        else if (isalnum(ch))
        {
            Prefix[k++] = ch;
        }
        else if (ch == '(')
        {
            while (stack[top] != ')')
            {
                Prefix[k++] = Pop();
            }
            x = Pop();
        }
        else
        {
            while (Precedence(stack[top]) >= Precedence(ch))
            {
                Prefix[k++] = Pop();
            }
            Push(ch);
        }
    }
    while (stack[top] != '#')
    {
        Prefix[k++] = Pop();
    }
    Prefix[k] = '\0';
}
int main()
{
    char Infix[MAX], Prefix[MAX];
    printf("Enter infix expression: ");
    gets(Infix);
    InfixToPrefix(Infix, Prefix);
    puts(strrev(Prefix));
}
