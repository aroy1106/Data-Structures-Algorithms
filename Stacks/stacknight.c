#include<stdio.h>
#include<stdlib.h>

# define MAX 10

typedef struct
{
    int data[MAX];
    int top;
}STACK;

int PUSH(STACK* s,int v)
{
    if(s->top == (MAX-1))
    {
        printf("Overflow\n");
        return 1;
    }
    else
    {
        s->top++;
        s->data[s->top] = v;
    }
    return 0;
}
void POP(STACK* s)
{
    if(s->top == -1)
        printf("Underflow\n");
    
    else
        s->top--;
    
}
void PEEK(STACK s)
{
    int i;
    for(i = 0 ; i <= s.top ; i++)
        printf("%d ",s.data[i]);
}

int main()
{
    int n;
    STACK s;
    s.top = -1;

    printf("Enter number of values you want to enter: ");
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)
    {
        int t;
        t = rand()%100;
        PUSH(&s,t);
    }
    printf("\nThe stack is: ");
    PEEK(s);
    printf("\n");

    POP(&s);
    printf("After first deletion, the stack is: ");
    PEEK(s);
    printf("\n");

    return 0;
}