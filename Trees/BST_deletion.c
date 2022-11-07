#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

TREE* create(TREE* root, int value)
{
    if(root == NULL)
    {
        TREE* cur; 
        cur = malloc(sizeof(TREE));
        cur->data = value;
        cur->left = cur->right = NULL;

        return cur;
    }
    if(value < root->data)
        root->left = create(root->left,value);
    else
       root->right = create(root->right,value);
    return root;
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
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
TREE* getmax(TREE* root)
{
    if(root == NULL)
        return root;
    if(root->right == NULL)
        return root;
    else
        return getmax(root->right);
}
TREE* delete(TREE* root, int value)
{
    if(root == NULL)
        return root;
    if (root->data < value)
    {
        root->right = delete(root->right,value);
        return root;
    }
    if(root->data > value)
    {
        root->left = delete(root->left,value);
        return root;
    }
    else
    {
        if(root->left != NULL && root->right != NULL)
        {
            TREE* cur = getmax(root->left);
            root->data = cur->data;
            root->left = delete(root->left,cur->data);
            return root;
        }
        else if(root->left == NULL)
        {
            TREE* temp = root->right;
            free(root);
            return temp;
        }
    }
}

int main()
{
    int n;
    TREE* root = NULL;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the data: ");
    for(int i = 0 ; i < n ; i++)
        scanf("%d",(arr+i));
    for(int i = 0 ; i < n ; i++)
        root = create(root,*(arr+i));
    
    printf("\nThe post order traversal of the tree is: ");
    postorder(root);

    printf("\nEnter the data you want to delete: ");
    scanf("%d",&n);
    root = delete(root,n);
    printf("\nThe final postorder is: ");
    postorder(root);

    return 0;
}