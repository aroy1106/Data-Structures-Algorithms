#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prv;
    int data;
    struct node* next;
};

void create(struct node** H, int x)
{
    struct node* ptr,* cur;

    for(int i = 0 ; i < x; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&cur->data);
        cur->next = cur->prv = NULL;

        if(*H == NULL)
            *H = ptr = cur->prv = cur->next = cur;
        else
        {
            cur->prv = ptr;
            ptr->next = cur;
            cur->next = *H;
            (*H)->prv = cur;
            ptr = cur;
        }
    }
}
void insert(struct node** H, int pos, int value)
{
    struct node* ptr = *H,* cur;

    cur = malloc(sizeof(struct node));
    cur->data = value;
    cur->next = cur->prv = NULL;

    for(int i = 1 ; i < (pos-1) ; i++)
    {
        ptr = ptr->next;
    }

    cur->prv = ptr;
    cur->next = ptr->next;
    ptr->next = cur;
    cur->next->prv = cur;
}
void display(struct node* H)
{
    struct node* ptr = H;

    while(ptr->next != H)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
}


int main()
{
    int n;
    struct node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    create(&head,n);

    printf("\nThe double cicular linked list is: ");
    display(head);
    printf("\n");

    int v,p;
    printf("\nEnter any value you want to add and also mention the position: ");
    scanf("%d %d",&v,&p);

    insert(&head,p,v);
    printf("\nThe final linked list is: ");
    display(head);
    printf("\n");

    return 0;
}