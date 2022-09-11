#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

void create(int n, struct node **H) // CREATION OF A DOUBLE LINKED LIST
{
    struct node *current;
    struct node *temp;
    int i;
    for (i = 0; i < n; i++)
    {
        current = malloc(n * sizeof(struct node));
        current->data = rand() % 100;
        current->prev = current->next = NULL;
        if (*H == NULL)
        {
            *H = current;
            temp = current;
        }
        else
        {
            current->prev = temp;
            temp->next = current;
            temp = current;
        }
    }
}

void display(struct node* H) // DISPLAY OF THE DOUBLE LINKED LIST
{
    struct node *ptr = H;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int search(struct node* H, int n)
{
    struct node* ptr;
    for(ptr = H ; ptr != NULL ; ptr = ptr->next)
    {
        if(ptr->data == n)
        {
            printf("Element found!");
            return 0;
        }
    
    }
    return 1;
}

void insert(struct node** H, int position, int v)
{
    struct node* cur;
    cur = malloc(sizeof(struct node));
    cur->data = v;
    cur->prev = cur->next = NULL;

    if(*H == NULL)
        *H = cur;
    else
    {
        struct node* ptr;
        int i = 1;
        for(i = 1, ptr = *H ; i < position ; i++, ptr = ptr->next);
        
    }
}
int main()
{
    struct node *head = NULL;
    int n;
    printf("Enter number of nodes: "); // ENTERING NUMBER OF NODES OF THE DOUBLY LINKED LIST
    scanf("%d", &n);

    create(n, &head);
    printf("The double linked list is: ");
    display(head);
    int num;
    printf("\nEnter a number you want to search: ");
    scanf("%d",&num);
    int result = search(head,num);

    if(result != 0)
        printf("Element not present in the linked list\n");
        
    return 0;
}
