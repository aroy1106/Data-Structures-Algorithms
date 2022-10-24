#include<stdio.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int top;
}STACK;

int PUSH(STACK* s, int v)
{
    if(s->top == MAX-1)
        return 1;
    else
    {
        s->top++;
        s->data[s->top] = v;
        return 0;
    }
}
void display(STACK s)
{
    int i = 0;
    while(i <= s.top)
    {
        printf("%d ",s.data[i]);
        i++;
    }
}
int POP(STACK* s,int* k)
{
    if(s->top == -1)
        return 1;
    *k = s->data[s->top];
    s->top--;
    return 0;
}
int main()
{
    STACK s;
    s.top = -1;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int v;
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the value you want to insert: ");
        scanf("%d",&v);
        int t = PUSH(&s,v);
        if(t == 0)
            printf("Value entered succesfully\n");
        else
        {
            printf("Overflow\n");
            break;
        }
    }
    printf("The data present in the stack is: ");
    display(s);

    int k;
    int r = POP(&s,&k);
    printf("\nThe data present in the stack after deleltion is: ");
    display(s);
    printf("\n");
    
    return 0;
}
