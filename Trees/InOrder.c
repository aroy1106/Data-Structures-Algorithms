#include<stdio.h>
#include<stdlib.h>

#define MAX 15

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

typedef struct 
{
    struct node* arr[MAX];
    int top;
}STACK;

struct node* create(int x)
{
    struct node* cur;

    cur = malloc(sizeof(struct node));

    cur->data = x;
    cur->left = cur->right = NULL;

    return cur;
}
// void PUSH(STACK* t, struct node* p)
// {
//     t->top++;
//     t->arr[t->top] = p;
// }
// void POP(STACK* t, struct node** p)
// {
//     *p = t->arr[t->top];
//     t->top--;
// }
// void in_order_traversal(struct node* root)
// {
//     struct node* cur = root, * k;
//     STACK s;
//     s.top = -1;

//     while(cur != NULL)
//     {
//         PUSH(&s,cur);
//         cur = cur->left;
//     }
//     while(s.top != -1)
//     {
//         POP(&s,&k);
//         printf("%d ",k->data);
        
//         cur = k->right;

//         while (cur != NULL)
//         {
//             PUSH(&s,cur);
//             cur = cur->left;
//         }  
//     }
// }
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);   
    }
}

int main()
{
    struct node* root = NULL;


    root = create(9);
    root->left = create(6);
    root->right = create(3);
    root->right->left = create(7);
    // root = create(1);
    // root->left = create(2);
    // root->right = create(3);
    // root->left->left = create(4);
    // root->left->right = create(5);
    // root->left->left->left = create(6);
    // root->left->left->right = create(11);
    // root->left->left->right->left = create(12);
    // root->left->left->right->right = create(13);
    // root->left->right->left = create(14);
    // root->right->left = create(7);
    // root->right->right = create(8);

    printf("The in-order traversal of the tree is: ");
    inorder(root);

    return 0;
}