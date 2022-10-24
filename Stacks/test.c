#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
}stack;

void PUSH(stack **s,char a)
{
    stack* cur, * ptr;

    cur = malloc(sizeof(stack));
    cur->c = a;
    cur->next = NULL;

    if(*s == NULL)
    {
        *s = cur;
        ptr = cur;
    }
    else
    {
        ptr->next = cur;
        ptr = cur;
    }
}
void PEEK(stack *s)
{
    stack *ptr=s;
    while(ptr!=NULL)
    {
        printf("%c",s->c);
        ptr=ptr->next;
    }
}
int main()
{
    char str[100];
    stack *top=NULL;
    printf("Enter a string\n");
    scanf("%s",str);
    int i;
    for(i=0 ; str[i]!='\0' ; i++)
    {
        // printf("%c ",str[i]);
        PUSH(&top,str[i]);
    }
    printf("the string is: ");
    PEEK(top);
    // printf("The string is %s\n",str);
    return 0;
}












