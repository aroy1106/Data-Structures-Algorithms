#include<stdio.h>
#include<stdlib.h>

struct polynomial
{
    int coef;
    int expo;
    struct polynomial* next;
};

void create(struct polynomial** P)
{
    int T;
    printf("Enter number of terms: ");
    scanf("%d",&T);
    
    for(int i = 0 ; i < T ; i++)
    {
        struct polynomial* cur;
        struct polynomial* ptr;
        cur = malloc(sizeof(struct polynomial));
        cur->next = NULL;
        printf("Enter the coefficient and the exponent: ");
        scanf("%d %d",&cur->coef,&cur->expo);

        if(*P == NULL)
        {
            *P = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}

void display(struct polynomial* P)
{
    struct polynomial* ptr = P;

    while(ptr->next != NULL)
    {
        printf("(%d,%d) + ",ptr->coef,ptr->expo);
        ptr = ptr->next;
    }
    printf("(%d,%d)",ptr->coef,ptr->expo);
}

int main()
{
    struct polynomial* head = NULL;
    create(&head);

    printf("\nThe polynomial is: ");
    display(head);

    return 0;
}