#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *getnode(int x)
{
    struct node *newn;
    newn = (struct node *)malloc(struct node);
    newn->data=x;
    newn->left = NULL;
    newn->right = NULL;
    return newn;
}

struct node *insert(struct node *root, int x)
{
    if(!root)
    root=getnode(x);
    else if(root->data>x)
    root->left=insert(root->left,x);
    else if(root->data<x)
    root->right=insert(root->right,x);

    return root;
}

struct node *search(struct node *root, int key)
{
    if(!root || root->data==key)
    return root;

    else if(root->data>key)
    return search(root->left,key);

    else if(root->data<key)
    return search(root->right,key);
}

void preorder(struct node *root)
{
    if(!root)
    return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(!root)
    return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(!root)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

static int c = -1;
void no_of_edges(struct node *root)
{
    if(!root)
    return;
    no_of_edges(root->left);
    c++;
    no_of_edges(root->right);
}

node successor(struct node *root)
{
    root = root->right;
    while(root->left)
    root=root->left

    return root;
}

node predecessor(struct node *root)
{
    root = root->left;
    while(root->right)
    root=root->right;

    return root;
}

int leafCount(struct node *root)
{
    if(!root)
    return 0;
    if(!root->left && !root->right)
    return 1;

    else
    return leafcount(root->left) + leafcount(root->right);
}

int Max(struct node *root)
{
    if(!root->right)
    return root->data;

    Max(root->right);
}

int Min(struct node *root)
{
    if(!root->left)
    return root->data;

    Min(root->left);
}



int main()
{
    struct node *root = NULL;


    return 0;
}