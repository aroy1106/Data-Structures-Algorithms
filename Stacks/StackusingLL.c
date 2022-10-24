#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}STACK;

void PUSH(STACK** T, int v)
{
    STACK* cur, * ptr;

    cur = malloc(sizeof(STACK));

    if(cur == NULL)
        printf("Stack Overflow!\n");
    
    cur->data = v;
    cur->next = NULL;

    if(*T == NULL)
    {
        *T = cur;
        // ptr = cur;
    }
    else
    {
        cur->next = *T;
        *T = cur;
        // ptr = cur;
    }
}
void POP(STACK** T)
{
    STACK* ptr = * T;

    if(*T == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        *T = ptr->next;
        free(ptr);
        ptr = *T;
    }
}
void display(STACK* T)
{
    STACK* ptr = T;

    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n;
    STACK* top = NULL;
    printf("Enter an element you want to enter into stack: ");
    scanf("%d",&n);
    PUSH(&top,n);

    char choice;
    while (1)
    {
        printf("Do you wish to continue? (y/n) ");
        scanf(" %c",&choice);

        if(choice == 'n')
            break;
        else
        {
            printf("Enter the element: ");
            scanf("%d",&n);

            PUSH(&top,n);
        } 
    }

    printf("\nThe stack is: ");
    display(top);
    printf("\n");
    
    POP(&top);
    printf("After first deletion the final stack is: ");
    display(top);
    printf("\n");

    POP(&top);
    printf("After second deletion the final stack is: ");
    display(top);
    printf("\n");
    
    return 0;
}