#include<stdio.h>
#include<stdlib.h>
//Search, Ceil, Floor

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

int Ceil(struct Node *root, int key2)
{
    // smallest val >= key
    int ceil = -1;
    while(root)
    {
        if(root->data == key2)
        {
            ceil = root->data;
            return ceil;
        }
        else
        {
            if(key2 > root->data)
            root = root->right;
            else{
            ceil = root->data;
            root = root->left;
            }
        }
    }
    return ceil;
}

int Floor(struct Node *root,int key3)
{
    // greatest val <= key
    int floor = -1;
    while(root)
    {
        if(root->data == key3)
        {
            floor = root->data;
            return floor;
        }
        else{
            if(root->data>key3)
            root = root->left;
            else
            {
                floor = root->data;
                root = root->right;
            }
        }
    }
    return floor;
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

        }
    }
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

    int key2,key3;

    printf("Enter the value whose ceiling value is to be found: \n");
    scanf("%d", &key2);  
    int c = Ceil(root,key2);
    printf("The ceiling value of %d is %d\n", key2, c);
    
    printf("Enter the value whose floor value is to be found: \n");
    scanf("%d", &key3);  
    int f = Floor(root,key3);
    printf("The floor value of %d is %d\n", key3, f);

    int d;
    printf("Enter the element you wish to delete: \n");
    scanf("%d", &d);
    root=delete(root,d);
    printf("Bst after deleting %d: \n", d);
    Inorder(root);
    
    return 0;
}