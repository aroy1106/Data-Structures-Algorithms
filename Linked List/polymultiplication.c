#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};
void create(struct node **h)
{
    int n;
    struct node *cur, *ptr;
    printf("Enter number of terms\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("enter the coefficient and exponent\n");
        scanf("%d %d", &cur->coef, &cur->exp);
        cur->next = NULL;
        if (*h == NULL)
        {
            *h = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void multiply(struct node *h1, struct node *h2, struct node **r)
{
    struct node *i, *j;
    for (i = h1; i != NULL; i = i->next)
    {
        for (j = h2; j != NULL; j = j->next)
        {
            struct node *cur, *ptr;
            cur = malloc(sizeof(struct node));
            cur->coef = i->coef * j->coef;
            cur->exp = i->exp + j->exp;
            cur->next = NULL;
            if (*r == NULL)
            {
                *r = cur;
                ptr = cur;
            }
            else
            {
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}
void simplify(struct node **h)
{
    struct node *p, *q, *prev;
    p = *h;

    while (p->next != NULL)
    {
        prev = p;
        q = p->next;
        while (q != NULL)
        {
            if (p->exp != q->exp)
            {
                prev = q;
                q = q->next;
            }
            else
            {
                p->coef += q->coef;
                prev->next = q->next;
                free(q);
                q = prev->next;
            }
        }
        p = p->next;
    }
}
void display(struct node *h)
{
    struct node *ptr;
    ptr = h;
    while (ptr->next != NULL)
    {
        printf("(%d,%d) + ", ptr->coef, ptr->exp);
        ptr = ptr->next;
    }
    printf("(%d,%d) ", ptr->coef, ptr->exp);
}
int main()
{
    struct node *head1 = NULL, *head2 = NULL, *result = NULL;
    create(&head1);
    create(&head2);
    printf("Polynomial 1: ");
    display(head1);
    printf("\nPolynomial 2: ");
    display(head2);
    printf("\nPolynomial after multiplying: ");
    multiply(head1, head2, &result);
    display(result);
    printf("\nFinal polynomial: ");
    simplify(&result);
    display(result);
    printf("\n");
    
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cof;
    int expo;
    struct node *next;
};

void create(struct node **H)
{
    int T;
    printf("Enter number of terms: ");
    scanf("%d", &T);

    struct node *cur, *ptr;

    for (int i = 0; i < T; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter the coefficient and the exponent: ");
        scanf("%d %d", &cur->cof, &cur->expo);
        cur->next = NULL;

        if (*H == NULL)
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

void product(struct node *H1, struct node *H2, struct node **R)
{
    struct node *i, *j, *cur, *ptr;
    for (i = H1; i != NULL; i = i->next)
    {
        for (j = H2; j != NULL; j = j->next)
        {
            cur = malloc(sizeof(struct node));
            cur->cof = i->cof * j->cof;
            cur->expo = i->expo + j->expo;
            cur->next = NULL;

            if (*R == NULL)
            {
                *R = cur;
                ptr = cur;
            }
            else
            {
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}

void simplify(struct node **H)
{
    struct node *p, *q, *prv;
    p = *H;

    while (p->next != NULL)
    {
        prv = p;
        q = p->next;
        while (q != NULL)
        {
            if (p->expo != q->expo)
            {
                prv = q;
                q = q->next;
            }
            else
            {
                p->cof += q->cof;
                prv->next = q->next;
                free(q);
                q = prv->next;
            }
        }
        p = p->next;
    }
}

void display(struct node *H)
{
    struct node *ptr = H;
    while (ptr->next != NULL)
    {
        printf("(%d,%d) + ", ptr->cof, ptr->expo);
        ptr = ptr->next;
    }
    printf("(%d,%d)", ptr->cof, ptr->expo);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *result = NULL;

    create(&head1);
    create(&head2);

    printf("\nThe first polynomial is: ");
    display(head1);
    printf("\nThe second polynomial is: ");
    display(head2);
    printf("\n");
    product(head1, head2, &result);
    simplify(&result);
    printf("The final polynomial is: ");
    display(result);

    return 0;
}*/