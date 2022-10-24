#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct 
{
    int data[MAX];
    int front;
    int back;
}QUEUE;

int enqueue(QUEUE* q, int value)
{
    if(q->back == (MAX-1))
    {
        printf("Queue Overflow!\n");
        return 1;
    }
    else
    {
        if(q->front == -1)
            q->front++;
        q->back++;
        q->data[q->back] = value;
        return 0;
    }
}
int dequeue(QUEUE* q)
{
    if(q->front > q->back)
    {
        printf("Queue Underflow!\n");
        return 1;
    }
    else
    {
        q->front++;
        return 0;
    }
}
void init(QUEUE* q)
{
    q->front = -1;
    q->back = -1;
}
void peek(QUEUE q)
{
    for(int i = q.front ; i <= q.back ; i++)
        printf("%d ",q.data[i]);
    
}

int main()
{
    QUEUE q;
    int v;
    init(&q);
    printf("Enter value you want to add: ");
    scanf("%d",&v);

    enqueue(&q,v);

    char choice = 'a';

    while(choice != 'n')
    {
        printf("Do you wish to continue?(y/n) ");   
        scanf(" %c",&choice);

        if(choice == 'y')
        {
            printf("Enter value you want to add: ");
            scanf("%d",&v);
            int result = enqueue(&q,v);

            if(result == 1)
                break;
        }
    }
    printf("\nThe data stored in queue is: ");
    peek(q);
    printf("\n");
    dequeue(&q);
    printf("\nThe final data present is: ");
    peek(q);
    printf("\n");

    return 0;
}
