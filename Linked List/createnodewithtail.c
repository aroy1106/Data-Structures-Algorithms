#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

int main()
{
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct node* cur;

    for(i = 0 ; i < n ; i++)
    {
        cur = malloc(sizeof(struct node));
        cur->data = rand()%10+1;
        cur->next = NULL;
        if (head == NULL)
        {
            head = cur;
            tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
        }
    }

    printf("The linked list is: ");
    cur = head;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }

    return 0;
}
