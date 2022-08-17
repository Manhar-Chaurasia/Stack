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
int IsOperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Precedence(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void InfixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch, x;
    Push('(');
    strcat(infix, ")");
    ch = infix[i];
    while (ch != '\0')
    {
        if (ch == '(')
        {
            Push(ch);
        }
        else if (isdigit(ch) || isalpha(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (IsOperator(ch) == 1)
        {
            x = Pop();
            while (IsOperator(x) == 1 && Precedence(x) >= Precedence(ch))
            {
                postfix[j] = x;
                j++;
                x = Pop();
            }
            Push(x);
            Push(ch);
        }
        else if (ch == ')')
        {
            x = Pop();
            while (x != '(')
            {
                postfix[j] = x;
                j++;
                x = Pop();
            }
        }
        else
        {
            printf("Invalid expression");
            exit(1);
        }
        i++;
        ch = infix[i];
        postfix[j] = '\0';
    }
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("The infix expression operates on single digit/letter variable\n");
    printf("Enter infix expression:\n");
    gets(infix);
    InfixToPostfix(infix, postfix);
    puts(postfix);
}
