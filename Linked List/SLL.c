#include<stdio.h>
#include<stdlib.h>

struct node                                 //DEFINING THE STRUCTURE OF LINKED LIST
{
    int data;
    struct node* next;
};

void create(struct node** h, int d)         //CREATING A SINGLE LINKED LIST
{
    struct node* cur;
    struct node* ptr;
    cur = malloc(sizeof(struct node));
    cur->data = d;
    cur->next = NULL;
    if (*h == NULL)
        *h = cur;
    else
    {
        ptr = *h;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = cur;
    }   
}

void insert(struct node** H, int position, int v)       //INSERTING VALUE TO THE LINKED LIST
{
    struct node* cur;
    cur = malloc(sizeof(struct node));
    cur->data = v;
    cur->next = NULL;

    if(*H == NULL)                                      //INSERTING VALUE TO THE EMPTY LINKED LIST
        *H = cur;
    else if(position == 1)                              //INSERTING VALUE TO THE THE FIRST POSITION
    {
        cur->next = *H;
        *H = cur;
    }
    else                                                //INSERTING VALUE IN THE MIDDLE OR LAST POSITION
    {
        struct node* ptr = *H;
        int i = 1;
        while(i < position-1)
        {
            ptr = ptr->next;
            i++;
        }
        cur->next = ptr->next;
        ptr->next = cur;
    }
}
void display(struct node* h)                            //DISPLAYING THE LINKED LIST
{
    struct node* ptr;
    ptr = h;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int search(struct node* H, int v)                       //SEARCHING AN ELEMENT IN THE LINKED LIST
{
    struct node* ptr;
    for (ptr = H ; ptr != NULL ; ptr = ptr->next)
    {
        if(ptr->data == v)
            return 0;
    }
    return 1;    
}

void deletion(struct node** H, int v)
{
    struct node* ptr, * prv;
    if(*H == NULL)
        printf("List is empty\n");
    else
    {   
        ptr = *H;
        while(ptr != NULL)
        {
            if(ptr->data == v)
                break;
            else
            {
                prv = ptr;
                ptr = ptr->next;
            }
        }
        if(ptr == NULL)
            printf("Element not found. Deletion aborted\n");
        else if(*H == ptr)
        {
            *H = ptr->next;
            free(ptr);
        }
        else
        {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}
int main()
{
    struct node* head = NULL;

    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i = 0 ; i < n ; i++)
        create(&head,i+1);
    
    printf("The data of the linked list is: ");
    display(head);

    int pos, num;
    printf("\nEnter the value you want to insert and at which position: ");
    scanf("%d %d",&num,&pos);

    insert(&head,pos,num);

    printf("\nThe final linked list is: ");
    display(head);

    int find;
    printf("\nEnter any number you want to search in the linked list: ");
    scanf("%d",&find);
    if(search(head,find) == 0)
        printf("Element found!\n");
    else 
        printf("Element not present\n");

    int delelement;
    printf("Enter the number you want to delete: ");
    scanf("%d",&delelement);

    deletion(&head,delelement);

    printf("\nThe linked list after deletion is: ");
    display(head);

    
    return 0;
}
