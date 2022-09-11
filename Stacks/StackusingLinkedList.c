#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct
{
    struct node* top;
}STACK;

int PUSH(STACK *s, int v)
{
    struct node* cur;
    cur = malloc(sizeof(struct node));

    if(cur == NULL)
        return 1;
    cur->data = v;
    cur->next = NULL;
    cur->next = s->top;
    s->top = cur;
    return 0;
}
void display(STACK* s)
{
    struct node* ptr;
    ptr = s;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    STACK* s;
    s->top = NULL;

    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        int t;
        printf("Enter a value: ");
        scanf("%d",&t);
        PUSH(&s,t);
    }
    printf("\nThe data present in the stack is: ");
    display(s);

    return 0;
}
*/
