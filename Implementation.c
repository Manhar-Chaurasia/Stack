// Array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 101
int A[MAX];
int tempst[MAX];
int top = -1;
int topp = -1;
void Push1(int data)
{
    if (topp == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    tempst[++topp] = data;
}
void Pop1()
{
    if (topp == -1)
    {
        printf("Underflow\n");
        return;
    }
    topp--;
}
void Push(int data)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    A[++top] = data;
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
void Display()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
void Find_Mid(int A[])
{
    int mid, c = 0;
    for (int i = 0; A[i] != 0; i++)
    {
        c++;
    }
    mid = c / 2;
    printf("Middle element= %d", A[mid]);
}
void Del_Mid_Stack()
{
    int c = 0, mid;
    for (int i = 0; i <= top; i++)
    {
        c++;
    }
    mid = (c / 2);
    for (int i = mid; i <= top; i++)
    {
        A[i] = A[i + 1];
    }
    top--;
}
int main()
{
    int ch, data;
    while (1)
    {
        printf("\n1 to Push\n");
        printf("2 to Pop\n");
        printf("3 to Display\n");
        printf("4 to exit\n");
        printf("5 to find middle element\n");
        printf("6 to delete middle element\n");
        printf("7 to delete middle ele----(gfg)\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            Push(data);
            break;

        case 2:
            Pop();
            break;

        case 3:
            Display();
            break;

        case 4:
            exit(1);
            break;

        case 5:
            Find_Mid(A);
            break;

        case 6:
            Del_Mid_Stack();
            break;
        }
    }
}
