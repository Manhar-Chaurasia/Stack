// Evalutaion of Postfix
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 101
#define POSTMAX 101
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
void EvalPostfix(char postfix[])
{
    int a = 0, b = 0, val;
    char ch;
    for (int i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            Push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            a = Pop();
            b = Pop();
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
    char Postfix[POSTMAX];
    printf("Enter postfix expression having operator +, -, *, /\n");
    printf("Enter right paranthesis ')' in the end of expression\n");
    for (int i = 0; i <= POSTMAX; i++)
    {
        scanf("%c", &Postfix[i]);
        if (Postfix[i] == ')')
        {
            break;
        }
    }
    EvalPostfix(Postfix);
}
