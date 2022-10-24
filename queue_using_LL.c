#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}QUEUE;

void enqueue(QUEUE** front, QUEUE** rear, int value)
{
    QUEUE* cur;

    cur = malloc(sizeof(QUEUE));

    if(cur == NULL)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        cur->data = value;
        cur->next = NULL;

        if(*front == NULL)
        {
            *front = cur;
            *rear = cur;
        }
        else
        {
            (*rear)->next = cur;
            *rear = cur;
        }
    }
}
void dequeue(QUEUE** front)
{
    QUEUE* ptr = *front;

    if(*front == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        *front = ptr->next;
        free(ptr);
    }
}
void peek(QUEUE* front)
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d",front->data);
}

int main()
{
    QUEUE* front = NULL;
    QUEUE* rear = NULL;

    int v;
    char choice;

    printf("Enter data: ");
    scanf("%d",&v);
    enqueue(&front,&rear,v);

    while(1)
    {
        printf("\nDo you wish to continue further?(y/n) ");
        scanf(" %c",&choice);

        if(choice == 'n')
            break;
        else
        {
            printf("Enter value of your choice: ");
            scanf("%d",&v);
            enqueue(&front,&rear,v);
        }
    }
    printf("\nThe data stored in queue is: ");
    peek(front);
    printf("\nAfter first deletion, the data present is: ");
    dequeue(&front);
    peek(front);
    printf("\nAfter second deletion, the data is: ");
    dequeue(&front);
    peek(front);
    printf("\n");
    
    return 0;
}