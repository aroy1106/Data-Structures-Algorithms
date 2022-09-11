#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coef;
    int expo;
    struct poly* next;
};

void create(struct poly** P)
{
    int T;
    printf("Enter number of terms: ");
    scanf("%d",&T);

    for(int i = 0 ; i < T ; i++)
    {
        struct poly* cur;
        struct poly* ptr;
        cur = malloc(sizeof(struct poly));
        cur->next = NULL;
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d",&cur->coef,&cur->expo);

        if(*P == NULL)
            *P = ptr = cur;
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void join(struct poly** P1,struct poly** P2)
{
    struct poly* ptr;

    for(ptr = *P1 ; ptr->next != NULL ; ptr = ptr->next);

    ptr->next = *P2;
    *P2 = NULL;
}
void display(struct poly* P)
{
    struct poly* ptr = P;
    while(ptr->next != NULL)
    {
        printf("(%d,%d) + ",ptr->coef,ptr->expo);
        ptr = ptr->next;
    }
    printf("(%d,%d)",ptr->coef,ptr->expo);
}

int main()
{
    struct poly* head1 = NULL;
    struct poly* head2 = NULL;
    create(&head1);
    create(&head2);

    printf("The first polynomial is: ");
    display(head1);
    printf("\nThe second polynomial is: ");
    display(head2);

    join(&head1,&head2);

    printf("\nThe final polynomial is: ");
    display(head1);

    return 0;
}