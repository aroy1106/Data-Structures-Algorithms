#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct
{
    struct node* front;
    struct node* rear;
}QUEUE;

void init(QUEUE* q)
{
    q->front = q->rear = NULL;
}
void insert(QUEUE* q, int v)
{
    struct node* cur,* ptr;

    cur = malloc(sizeof(struct node));

    if(cur == NULL)
    {
        printf("Overflow!");
        return;
    }
    else
    {
        cur->data = v;
        cur->next = NULL;

        if(q->front == NULL)
        {
            q->front = cur;
            q->rear = cur;
        }
        else
        {
            q->rear->next = cur;
            q->rear = cur;
        }
    }
}
void deletion(QUEUE* q)
{
    if(q->front == NULL)
    {
        printf("Underflow");
    }
}
void display(QUEUE q)
{
    while(q.front != NULL)
    {
        printf("%d ",(q.front).data);
        q.front = (q.front).next;
    }
}
int main()
{
    QUEUE q;
    init(&q);
    insert(&q,10);
    insert(&q,20);
    insert(&q,30);
    printf("The queue is: ");
    display(q);

    return 0;
}
