//Linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
int stack[51];
int topp=-1;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top;
void Push(int data)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=top;
    top=temp;
}
void intoStack()
{
    struct Node *temp=top;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        stack[++topp]=temp->data;
        temp=temp->next;
    }
    printf("\nReversed Linked list:\n");
    while (topp>=0)
    {
        printf("%d\t",stack[topp--]);
    }
}
void Pop()
{
    struct Node *temp=top;
    if (top==NULL)
    {
        return;
    }
    top=top->next;
    free(temp);    
}
void Display()
{
    struct Node *temp=top;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    
}
void Del_Mid()
{
    int c=4,n;
    n=(c/2);
    struct Node *temp=top;
    for (int i = 0; i < n-2; i++)
    {
        temp=temp->next;
    }
    struct Node *temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}
int main()
{
    int ch,data;
    while (1)
    {
        printf("\n1 to Push\n");
        printf("2 to Pop\n");
        printf("3 to Display\n");
        printf("4 to exit\n");
        printf("5 to push pointer\n");
        printf("6 to delete middle position\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d",&data);
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
            intoStack();
            break;

        case 6:
            Del_Mid();
            break;
        }
    }
}
