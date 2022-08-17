// find mid & delete mid from stack (DLL)
#include <stdio.h>
#include <stdlib.h>
struct DLLNode
{
    int data;
    struct DLLNode *prev;
    struct DLLNode *next;
};
struct mystack
{
    int count;
    struct DLLNode *head;
    struct DLLNode *mid;
};
struct mystack *createstack()
{
    struct mystack *ms = (struct mystack *)malloc(sizeof(struct mystack));
    ms->count = 0;
    return ms;
};
void Push(struct mystack *ms, int data)
{
    struct DLLNode *newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = ms->head;
    ms->count += 1;

    if (ms->count == 1)
    {
        ms->mid = newNode;
    }
    else
    {
        ms->head->prev = newNode;
        if (ms->count & 1)
        {
            ms->mid = ms->mid->prev;
        }
    }
    ms->head = newNode;
}
int Find_Mid(struct mystack *ms)
{
    if (ms->count == 0)
    {
        printf("stack empty\n");
        return -1;
    }
    return ms->mid->data;
}
void Del_Mid(struct mystack *ms)
{
    if (ms->count == 0)
    {
        printf("Stack empty\n");
        return;
    }
    ms->count -= 1;

    ms->mid->next->prev = ms->mid->prev;
    ms->mid->prev->next = ms->mid->next;

    if (ms->count % 2 != 0)
    {
        ms->mid = ms->mid->next;
    }
    else
    {
        ms->mid = ms->mid->prev;
    }
}
int Pop(struct mystack *ms)
{
    if (ms->count == 0)
    {
        printf("Stack empty\n");
        return -1;
    }
    struct DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != NULL)
    {
        ms->head->prev = NULL;
    }
    ms->count -= 1;
    if (!((ms->count) & 1)) // odd
    {
        ms->mid = ms->mid->next;
    }
    free(head);
    return item;
}
int main()
{
    struct mystack *ms = createstack();
    Push(ms, 1);
    Push(ms, 2);
    Push(ms, 3);
    Push(ms, 4);
    Push(ms, 5);
    Push(ms, 6); // top
    printf("%d = mid", Find_Mid(ms));
    Del_Mid(ms);
    printf("\n%d = mid", Find_Mid(ms));
    printf("\n%d popped from stack", Pop(ms));
    return 0;
}
