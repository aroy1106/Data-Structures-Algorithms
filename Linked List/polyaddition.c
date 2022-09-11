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
        struct poly* cur, * ptr;
        cur = malloc(sizeof(struct poly));
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d",&cur->coef,&cur->expo);
        cur->next = NULL;

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
void join(struct poly** P1, struct poly** P2)
{
    struct poly* ptr;

    for(ptr = *P1 ; ptr->next != NULL ; ptr = ptr->next);

    ptr->next = *P2;
    *P2 = NULL;
}
void simplify(struct poly** P)
{
    struct poly* p, * q, * prv;
    p = *P;
    while (p != NULL)
    {
        prv = p;
        q = p->next;

        while(q != NULL)
        {
            if(p->expo != q->expo)
            {
                prv = q;
                q = q->next;
            }
            else
            {
                p->coef += q->coef;
                prv->next = q->next;
                free(q);
                q = prv->next;
            }
        }
        p = p->next;
    }
}
void rearrange(struct poly** P)
{
    struct poly* p, * q;
    p = *P;

    while (p != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(p->expo < q->expo)
            {
                int c,e;
                c = q->coef;
                q->coef = p->coef;
                p->coef = c;
                e = q->expo;
                q->expo = p->expo;
                p->expo = e;
            }
            else
                q = q->next;
        }
        p = p->next;     
    }
}
void display(struct poly* P)
{
    struct poly* ptr = P;

    while (ptr->next != NULL)
    {
        printf("(%d,%d) + ",ptr->coef,ptr->expo);
        ptr = ptr->next;
    }
    printf("(%d,%d)",ptr->coef,ptr->expo);
}

int main()
{
    struct poly* head1 = NULL, * head2 = NULL;

    create(&head1);
    create(&head2);
    
    printf("The first polynomial is: ");
    display(head1);
    printf("\n");
    printf("The second polynomial is: ");
    display(head2);
    printf("\n");

    printf("After addition, the resultant polynomial is: ");
    join(&head1,&head2);
    simplify(&head1);
    rearrange(&head1);
    display(head1);

    return 0;
}
