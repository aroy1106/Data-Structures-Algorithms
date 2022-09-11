#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** H)                //CREATION OF SINGLE CIRCULAR LINKED LIST
{
    struct node* cur;
    struct node* ptr;
    cur = malloc(sizeof(struct node));
    cur->data = rand()%100;
    cur->next = NULL;

    if(*H == NULL)
    {
        *H = cur;
        cur->next = cur;
        ptr = cur;
    }
    else
    {
        cur->next = ptr->next;
        ptr->next = cur;
        ptr = cur;
    }
}

void display(struct node* H)                //DISPLAY OF SINGLE CIRCULAR LINKED LIST
{
    struct node* ptr = H;
    if(H == NULL)
        printf("Empty");
    while(ptr->next != H)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d ",ptr->data);

}
int main()
{
    struct node* head = NULL;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
        create(&head);
    
    printf("The Linked List is: ");
    display(head);

    return 0;
}