#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *head = NULL;

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    struct node* cur;
    struct node* ptr;
    for(i = 0 ; i < n ; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",cur->data);
        cur->next = NULL;
        if (head == NULL)
        {
            head = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }        
    }
    
    return 0;
}