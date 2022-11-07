#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

TREE* create(int x)
{
    TREE* cur;

    cur = malloc(sizeof(TREE));
    cur->data = x;
    cur->left = cur->right = NULL;

    return cur;
}
int array[100];
int i = 0;

int* preorder(TREE* root)
{
    if(root != NULL)
    {
        array[i] = root->data;
        i++;
        preorder(root->left);
        preorder(root->right);
    }
    return array;
}
int* inorder(TREE* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        array[i]
    }
}
int main()
{
    TREE* root = NULL;
    srand(time(0));
    root = create(rand()%100+1);
    root->left = create(rand()%100+1);
    root->right = create(rand()%100+1);
    root->left->right = create(rand()%100+1);
    root->left->right->left = create(rand()%100+1);
    root->left->left = create(rand()%100+1);
    root->right->left = create(rand()%100+1);
    root->right->right = create(rand()%100+1);
    root->right->left->right = create(rand()%100+1);
    root->right->right->right = create(rand()%100+1);

    printf("The pre-order of the tree is: ");
    preorder(root);
    for(int k = 0 ; k < i ; k++)
        printf("%d ",*(array+k));

    return 0;
}