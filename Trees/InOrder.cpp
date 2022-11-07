#include<iostream>
using namespace std;

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}TREE;

TREE* create(int x)
{
    TREE* cur;

    cur = new TREE;
    cur->data = x;
    cur->left = cur->right = NULL;

    return cur;
}
void preorder(TREE* root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    TREE* root = NULL;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the data: ";
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    
    for(int i = 0 ; i < n ; i++)
        create(arr[i]);
    
}