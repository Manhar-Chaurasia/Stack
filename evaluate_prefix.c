// Evaluation of Prefix
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101
#define PREMAX 101
int stack[MAX];
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
void EvalPrefix(char Prefix[])
{
    int a = 0, b = 0, val;
    char ch;
    for (int i = strlen(Prefix); i >= 0; i--)
    {
        ch = Prefix[i];
        if (isdigit(ch))
        {
            Push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            b = Pop();
            a = Pop();
            switch (ch)
            {
            case '+':
                val = a + b;
                break;

            case '-':
                val = b - a;
                break;

            case '*':
                val = a * b;
                break;

            case '/':
                val = b / a;
                break;
            }
            Push(val);
        }
    }
    printf("Result= %d", Pop());
}
int main()
{
    char Prefix[PREMAX];
    printf("Enter postfix expression having operator +, -, *, /\n");
    printf("Enter right paranthesis ')' in the end of expression\n");
    for (int i = 0; i <= PREMAX; i++)
    {
        scanf("%c", &Prefix[i]);
        if (Prefix[i] == ')')
        {
            break;
        }
    }
    EvalPrefix(Prefix);
}
