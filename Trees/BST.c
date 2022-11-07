#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

TREE* create(TREE* root, int data)
{
    if(root == NULL)
    {
        TREE* cur;
        cur = malloc(sizeof(TREE));
        cur->data = data;
        cur->left = cur->right = NULL;

        return cur;
    }
    if(data < root->data)
        root->left = create(root->left,data);
    if(data > root->data)
        root->right = create(root->right,data);
    return root;
}
void preorder(TREE* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(TREE* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(TREE* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}
TREE* search(TREE* root, int v)
{
    if(root == NULL)
        return root;
    if(root->data == v)
        return root;
    if(v > root->data)
        return search(root->right,v);
    else
        return search(root->left,v);
}
int main()
{
    int n;
    TREE* root = NULL;

    printf("Enter the number of elements of the tree: ");
    scanf("%d",&n);
    int a[n];

    // printf("Enter the elements: ");
    // srand(time(0));
    for(int i = 0 ; i < n ; i++)
        *(a+i) = rand()%50+1;
    
    for (int i = 0; i < n; i++)
        root = create(root,a[i]);
    
    // printf("\nThe pre-order traversal of the tree is: ");
    // preorder(root);
    // printf("\nThe in-order traversal of the tree is: ");
    // inorder(root);
    // printf("\nThe post-order traversal of the tree is: ");
    // postorder(root);

    // printf("Enter a number: ");
    // scanf("%d",&n);
    // root = create(root,n);
    // printf("\nThe post-order of the final tree is: ");
    // postorder(root);
    // printf("\nThe in-order of the final tree is: ");
    // inorder(root);

    printf("\nEnter a number you want to search in the tree: ");
    scanf("%d",&n);
    TREE* ptr;
    ptr = search(root,n);
    if(ptr == NULL)
        printf("Tree is empty\n");
    else if(ptr == root)
        printf("%d is present at the root(%x)",n,ptr);
    else
        printf("%d is present at %x location",n,ptr);
    printf("\nThe post-order of the final tree is: ");
    postorder(root);
    printf("\nThe in-order of the final tree is: ");
    inorder(root);

    return 0;
}