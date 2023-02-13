#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};
typedef struct Node *node;

node create(int data)
{
    node newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = 0;
    newnode->right = 0;
    return newnode;
}

node insert(node root, int data)
{
    if (root == 0)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int search(node root, int n)
{
    if (root == 0)
        return 0;
    if (n == root->data)
        return 1;
    if (n < root->data)
        return search(root->left, n);
    else if (n > root->data)
        return search(root->right, n);
}

void inorder(node root)
{
    if (root == 0)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

node orderpre(node root)
{
    root = root->left;
    while (root->right != 0)
        root = root->right;
    return root;
}

node deletenode(node root, int data)
{
    if (root == 0)
    {
        printf("does not exist\n");
        return 0;
    }

    node ipre;
    if (data < root->data)
        root->left = deletenode(root->left, data);
    else if (data > root->data)
        root->right = deletenode(root->right, data);
    else
    {
        if (root->right == 0 && root->left == 0)
        {
            free(root);
            root = 0;
        }
        else if (root->left == 0)
        {
            node ptr = root;
            root = root->right;
            free(ptr);
        }
        else if (root->right == 0)
        {
            node ptr = root;
            root = root->left;
            free(ptr);
        }
        else
        {
            ipre = orderpre(root);
            root->data = ipre->data;
            root->left = deletenode(root->left, ipre->data);
        }
    }
    return root;
}

void menu()
{
    printf("------menu-----\n");
    printf("1.Insert\n");
    printf("2.Search\n");
    printf("3.Print\n");
    printf("4.Delete\n");
    printf("5.Exit\n");
    printf("---------------\n");
}

int main()
{
    node root = 0;
    int choice, n, f = 0;
    while (1)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("enter element to be searched\n");
            scanf("%d", &n);
            f = search(root, n);
            if (f == 1)
                printf("yes\n");
            else
                printf("No\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter element to be deleted\n");
            scanf("%d", &n);
            root = deletenode(root, n);
            break;
        case 5:
            exit(0);
        }
    }
}