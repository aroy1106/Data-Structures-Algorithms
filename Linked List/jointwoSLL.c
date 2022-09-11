#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** H, int no_of_nodes)
{
    struct node* cur;
    struct node* ptr;
    
    for(int i = 0 ; i < no_of_nodes ; i++)
    {
        cur = malloc(sizeof(struct node));
        cur->data = rand()%50;
        cur->next = NULL;
        if(*H == NULL)
        {
            *H = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}

void join(struct node** H1, struct node** H2)
{
    struct node* ptr;

    for(ptr = *H1 ; ptr->next != NULL ; ptr = ptr->next);

    ptr->next = *H2;
    *H2 = NULL;
}

void display(struct node* H)
{
    struct node* ptr = H;

    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int n1,n2;
    printf("Enter number of nodes of first linked list: ");
    scanf("%d",&n1);
    create(&head1,n1);
    printf("Enter number of nodes of second linked list: ");
    scanf("%d",&n2);
    create(&head2,n2);

    printf("The first linked list is: ");
    display(head1);
    printf("\n");
    printf("The second linked list is: ");
    display(head2);
    printf("\n");

    printf("After joining two linked list, the result is: ");
    join(&head1,&head2);
    display(head1);
    
    return 0;
}