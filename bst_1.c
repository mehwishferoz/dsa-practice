#include<stdio.h>
#include<stdlib.h>
//Search, Insert, Delete, Preorder

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *getNode(int n)
{
    struct Node* newn;
    newn = (struct Node*)malloc(sizeof(struct Node));
    newn->data = n;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

struct Node *insert(struct Node *root, int x)
{
    if(root==NULL)
    root = getNode(x);

    else if(root->data<x)
    root->right = insert(root->right,x);

    else if(root->data>x)
    root->left = insert(root->left,x);

    return root;
}

void Inorder(struct Node *root)
{
    if(!root)
    return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

int search(struct Node* root, int k)
{
    if(!root)
    return 0;
    else if(root->data == k)
    return 1;
    else if(k>root->data)
    search(root->right,k);
    else if(k<root->data)
    search(root->left,k);
}

struct Node* predecessor(struct Node *root)
{
    struct Node *temp=root->left;
    while(temp->right)
    temp=temp->right;

    return temp;
}

struct Node* delete(struct Node *root, int d)
{
    if(!root)
    printf("Tree is empty\n");

    else if(d>root->data)
    root->right = delete(root->right,d);

    else if(d<root->data)
    root->left = delete(root->left,d);

    else
    {
        struct Node* ipre;
        if(!root->left && !root->right)
        {
            free(root);
            root=NULL;
        }
        else if(!root->left)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(!root->right)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            ipre = predecessor(root);
            root->data = ipre->data;
            root->left = delete(root->left,d);
        }
    }
    return root;
}

int main(){

    struct Node *root = NULL;
    int n, x;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value to be inserted: \n");
        scanf("%d", &x);
        root = insert(root,x);
    }

    printf("Inorder traversal: \n");
    Inorder(root);
    
    int k;
    printf("Enter the key to be searched: \n");
    scanf("%d", &k);
    int s = search(root,k);
    if(!s)
    printf("Not found\n");
    else
    printf("Found\n");  
    
    int d;
    printf("Enter the element you wish to delete: \n");
    scanf("%d", &d);
    root=delete(root,d);
    printf("Bst after deleting %d: \n", d);
    Inorder(root);
    
    return 0;
}