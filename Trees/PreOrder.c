#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

typedef struct stack
{
    TREE* data;
    struct stack* next;
}STACK;

void PUSH(STACK** top, TREE* T)
{
    STACK* cur;

    cur = malloc(sizeof(STACK));

    cur->data = T;
    cur->next = NULL;

    if(*top == NULL)
        *top = cur;
    else
    {
        cur->next = *top;
        *top = cur;
    }
} 
void POP(STACK** top, TREE** T)
{
    STACK* ptr = *top;
    *T = ptr->data;
    *top = ptr->next;
    free(ptr);
}
// void preorder(TREE* root)
// {
//     TREE* k = root;
//     STACK* s = NULL;
    
//     if(root == NULL)
//     {
//         printf("Tree does not exist\n");
//         return;
//     }
//     else
//     {
//         PUSH(&s,root);

//         while (s != NULL)
//         {
//             POP(&s,&k);
//             printf("%d ",k->data);
//             if(k->right != NULL)
//                 PUSH(&s,k->right);
//             if(k->left != NULL)
//                 PUSH(&s,k->left);
//         }
//     }
// }
void pre_order(TREE* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
TREE* create(int v)
{
    TREE* cur;

    cur = malloc(sizeof(TREE));

    cur->data = v;
    cur->left = cur->right = NULL;

    return cur;
}

int main()
{
    TREE* root = NULL;

    root = create(5);
    root->left = create(9);
    root->left->left = create(7);
    root->left->right = create(8);
    root->left->right->left = create(4);
    root->right = create(6);
    root->right->right = create(3);
    root->right->right->left = create(2);
    root->right->right->right = create(1);

    printf("\nThe preorder traversal of tree is: ");
    pre_order(root);
    printf("\n");

    return 0;
}
