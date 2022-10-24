#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} stack;
void enqueue(stack **t, int v)
{
    stack *ptr, *cur;

    cur = malloc(sizeof(stack));

    if (cur == NULL)
        printf("Overflow");
    else
    {
        cur->data = v;
        cur->next = NULL;

        if (*t == NULL)
        {
            *t = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void dequeue(stack **t)
{
    stack *ptr = *t;

    if (*t == NULL)
        printf("Underflow");
    else
    {
        *t = ptr->next;
        free(ptr);
    }
}
void peek(stack *t)
{
    stack *ptr = t;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    stack *top = NULL;
    int value;

    for(int i = 0 ; i < 5 ; i++)
    {
        printf("Enter the value: ");
        scanf("%d",&value);
        enqueue(&top,value);
    }
    printf("\nThe queue is\n");
    peek(top);

    printf("\nThe queue after deletion is\n");
    dequeue(&top);
    peek(top);
    printf("\n");
    // enqueue(&top, 10);
    // enqueue(&top, 20);
    // enqueue(&top, 30);
    // printf("\nThe queue is: ");
    // peek(top);
    // dequeue(&top);
    // printf("\nThe final queue is: ");
    // peek(top);
    // printf("\n");
    return 0;
}