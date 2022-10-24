#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} STACK;

void enqueue(STACK** T, int v)
{
    STACK *cur, *ptr;

    cur = malloc(sizeof(STACK));

    if (cur == NULL)
    {
        printf("Overflow!\n");
        return;
    }
    cur->data = v;
    cur->next = NULL;

    if (*T == NULL)
    {
        *T = cur;
        ptr = cur;
    }
    else
    {
        ptr->next = cur;
        ptr = cur;
    }
}
void dequeue(STACK **T)
{
    STACK *ptr = *T;

    if (ptr == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    *T = ptr->next;
    free(ptr);
}
void display(STACK *T)
{
    if (T == NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    else
    {
        STACK* ptr = T;
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
            return;
    }
}
void peek(STACK *T)
{
    printf("%d\n", T->data);
    return;
}
int main()
{
    STACK *top = NULL;
    int choice;

    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int n;
            char ch;

            while (1)
            {
                printf("Enter a value: ");
                scanf("%d", &n);
                enqueue(&top, n);
                printf("Hello!\n");
                printf("Do you wish to continue?(y/n) ");
                scanf(" %c", &ch);
                if (ch == 'n')
                    break;
                else
                    continue;
            }
            printf("Operation successfull!\n");
        }
        else if (choice == 2)
            dequeue(&top);
        else if (choice == 3)
            display(top);
        else if (choice == 4)
            peek(top);
        else if (choice == 5)
            break;
    }

    return 0;
}