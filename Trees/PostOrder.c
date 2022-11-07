#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

typedef struct
{
    struct node* arr[MAX];
    int top;    
}STACK;

struct node* create(int x)
{
    struct node* cur;

    cur = malloc(sizeof(TREE));
    cur->data = x;
    cur->left = cur->right = NULL;

    return cur;
}
void PUSH(STACK* s, TREE* t)
{
    s->top++;
    s->arr[s->top] = t;
}
void POP(STACK* s, TREE** t)
{
    *t = s->arr[s->top];
    s->top--;
}
void post_order_traversal(TREE* t)
{
    TREE* cur = t, * x, * y;
    STACK s;
    s.top = -1;

    while(cur != NULL)
    {
        if(cur->right != NULL)
            PUSH(&s,cur->right);
        PUSH(&s,cur);
        cur = cur->left;
    }

    while(s.top != -1)
    {
        POP(&s,&x);

        if(x->right == NULL || s.top == -1)
            printf("%d ",x->data);
        else
        {
            POP(&s,&y);

            if(x->right == y)
            {
                PUSH(&s,x);
                cur = y;
                while(cur != NULL)
                {
                    if(cur->right != NULL)
                        PUSH(&s,cur->right);
                    PUSH(&s,cur);
                    cur = cur->left;
                }
            }
            else
            {
                printf("%d ",x->data);
                PUSH(&s,y);
            }
        }
    }
}

int main()
{
    struct node* root = NULL;

    root = create(1);
    root->left = create(2);
    root->right = create(5);
    root->left->left = create(4);
    root->left->right = create(3);
    root->right->left = create(6);
    root->right->left->right = create(7);
    root->right->left->right->left = create(8);
    root->right->left->right->right = create(9);

    printf("The post-order traversal of the tree is: ");
    post_order_traversal(root);

    return 0;
}