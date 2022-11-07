#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnode(int x)
{
    // struct node *temp;
    // int data;int choice;
    // temp=(struct node*)malloc (sizeof(struct node));

    // printf("press 0  to exit\n");
    // printf("press 1 for new node\n");
    // printf("enter your choice\n");
    // scanf("%d",&choice);
    // if(choice==0)
    // {
    //     return 0;
    // }
    // else
    // {
    //     printf("enter the data");
    //     scanf("%d",&temp->data);
    //     temp->left=NULL;
    //     temp->right=NULL;

    //     return temp;
    // }
    struct node *cur;
    cur = malloc(sizeof(struct node));
    cur->data = x;
    cur->left = cur->right = NULL;
    return cur;
}
void inordertraversal(struct node *root)
{
    if(root != NULL)
    {
        printf("%d---->", root->data);
        inordertraversal(root->left);
        inordertraversal(root->right);
    }
}
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d---->", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }   
    
}
void postordertraversal(struct node *root)
{
    if (root == NULL)
        return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    printf("%d---->", root->data);
}
// struct node *insertleft(struct node *root,int data)
// {
//   root->left=getnode();
//   scanf("%d",& root->left->data);
//   return root->left;
// }

// struct node *insertright(struct node *root,int data)
// {
//   root->right=getnode();
//   printf("enter the data\n");
//   scanf("%d",& root->right->data);
//   return root->right;
// }

int main()
{
    int choice;
    struct node *root = NULL;
    while(1)
    {        
        printf("\npress 0  to exit\n");
        printf("press 1 for new node\n");
        printf("press 2 for in-order traversal\n");
        printf("press 3 for pre-order traversal\n");
        printf("press 4 for post-order traversal\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        if (choice == 0)
            printf("Program exit\n");
        else if (choice == 1)
        {
            root = getnode(10);
            root->left = getnode(20);
            root->right = getnode(39);
            root->left->left = getnode(12);
            root->right->left = getnode(32);
            root->left->right = getnode(45);
            printf("Done\n");
        }
        else if (choice == 2)
        {
            printf("inorder traversal: ");
            inordertraversal(root);
        }
        else if (choice == 3)
        {
            printf("preorder traversal\n");
            preordertraversal(root);
        }
        else if (choice == 4)
        {
            printf("pastorder traversal\n");
            postordertraversal(root);
        }
        char c;
        printf("\nDo you wish to continue further?(y/n) ");
        scanf(" %c",&c);
        if (c == 'n')
            break;  
    }
    

    // insertleft(root,root->left->data);
    // insertright(root,root->right->data);

    return 0;
}