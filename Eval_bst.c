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
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node insert(node root, int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int count = 0;

node search(node root, int n)
{
    if (root == NULL || n == root->data)
    {
        printf("%d\n", count);
        return root;
    }

    if (n < root->data)
    {
        count++;
        return search(root->left, n);
    }
    else if (n > root->data)
    {
        count++;
        return search(root->right, n);
    }
}

void level_one(node root)
{
    if(root->left == NULL && root->right == NULL)
    printf("0 nodes at level 1\n");
    else if(root->left == NULL && root->right != NULL)
    printf("1 node at level 1\n");
    else if(root->left != NULL && root->right == NULL)
    printf("1 node at level 1\n");
    else 
    printf("2 nodes at level 1\n"); 
}

void inorder(node root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

static int c=-1;
void no_of_edges(node root)
{
    if(root)
    {
    no_of_edges(root->left);
    c++;
    no_of_edges(root->right);
    }
}

node orderpre(node root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

node deletenode(node root, int data)
{
    if (root == NULL)
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
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left->data == data)
        {
            node ptr = root;
            root = root->right;
            free(ptr);
        }
        else if (root->right == NULL)
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

void out_deg(node root)
{
    if (root->left == NULL && root->right == NULL)
        printf("\nOut-degree of root=0");
    else if (root->left == NULL && root->right != NULL)
        printf("\nOut-degree of root=1");
    else if (root->left != NULL && root->right == NULL)
        printf("\nOut-degree of root=1");
    else
        printf("\nOut-degree of root=2");
}

int leafCount(node root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leafCount(root->left) + leafCount(root->right);
}

int maxValue(node root)
{
    if (root->right == NULL)
        return root->data;
    else
    {
        count++;
        maxValue(root->right);
    }
}

int findMin(node root){
    if (root->left == NULL)
        return root->data;
    return findMin(root->left);
}

node deleteLessThan(node root, int key)
{
    if (root == NULL)
        return root;
    root->left = deleteLessThan(root->left, key);
    if (root->data < key)
    {
        node temp = root->right;
        free(root);
        return temp;
    }
    root->right = deleteLessThan(root->right, key);
    return root;
}

int countGreaterNodes(node root, int key)
{
    if (root == NULL)
        return 0;
    int count1 = 0;
    if (root->data > key)
    {
        count1 = 1 + countGreaterNodes(root->left, key) + countGreaterNodes(root->right, key);
    }
    else
    {
        count1 = countGreaterNodes(root->right, key);
    }
    return count1;
}

void menu()
{
    printf("\n------menu-----\n");
    printf("1.Print the In-degree of the root node of the tree\n");
    printf("2.Print the out-degree of the root node\n");
    printf("3.Implement the recursive tree search algorithm\n");
    printf("4.Print the number of edges in the tree\n");
    printf("5.Delete all the nodes lesser than user given K from the tree\n");
    printf("6.Count the number of nodes having a value greater than the given value K\n");
    printf("7.Print the in-order successor of the given item\n");
    printf("8.Find the minimum valued item from the tree\n");
    printf("9.Count the number of external nodes\n");
    printf("10.Print the address of the root node\n");
    printf("11.Find and print the number of comparisons made to search a given item from the tree\n");
    printf("12.Count the number of nodes present at level 1 of the tree\n");
    printf("13.Implement the insert_into_bst function using recursion\n");
    printf("14.Count and print the number of leaf nodes present in the tree\n");
    printf("15.Find the memory occupied by the tree in terms of bytes\n");
    printf("16.Find the number of edges between the root node and the largest element in the tree\n");
    printf("17.Print the total out-degree of all the leaf nodes\n");
    // printf("18.Find and delete all the duplicate nodes from the tree\n");
    printf("19.Print the in-order predecessor of the given item\n");
    printf("20.Find the maximum valued item in the tree\n");
    printf("21.Find and print the number of comparisons made to find the maximum element\n");
    printf("22.Exit\n");
    printf("---------------\n");
}

int main()
{
    node root = NULL, s;
    int choice, n, f = 0, ln;
    while (1)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The In-degree of the root node of the tree is always 0\n");
            break;

        case 2:
            out_deg(root);
            break;

        case 3:
            printf("Enter element to be searched\n");
            scanf("%d", &n);
            root = search(root, n);
            if (root != NULL)
                printf("yes\n");
            else
                printf("No\n");
            break;

        case 4:
            no_of_edges(root);
            printf("No. of edges = %d\n", c);
            break;

        case 5:
            printf("enter key");
            scanf("%d", &n);
            root = deleteLessThan(root, n);
            printf("Tree after deltetion\n");
            inorder(root);
            break;

        case 6:
            printf("enter key");
            scanf("%d", &n);
            printf("number of nodes greater than %d is=%d", n, countGreaterNodes(root, n));
            break;
        
        case 7:
            printf("enter key");
            scanf("%d", &n);
            s = search(root, n);
            ln = findMin(s->right);
            printf("Inorder successor of the key=%d", ln);
            break;
        
        case 8:
            ln = findMin(root);
            printf("min element=%d", ln);
            break;

        case 9:
            ln = leafCount(root);
            printf("\nNumber of external nodes=%d", ln + 1);
            break;

        case 10:
            printf("Address of root=%p", root);
            break;

        case 11:
            printf("Enter element to be searched\n");
            scanf("%d", &n);
            count = 0;
            root = search(root, n);
            printf("Number of comparisons=%d", count);

        case 12:
            level_one(root);
            break;

        case 13:
            printf("Enter data\n");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        
        case 14:
            ln = leafCount(root);
            printf("\nNumber of leaf nodes=%d", ln);
            break;

        case 15:
            char* bytes1 = (char*)malloc(sizeof(struct Node));
            char* bytes2 = (char*)malloc(sizeof(root));
            printf("%u bytes is the memory used by the tree\n", (bytes2) - (bytes1));
            break;

        case 16:
            count = 0;
            int m = maxValue(root);
            printf("Number of edges=%d", count);
            break;
        
         case 17:
            ln = leafCount(root);
            printf("\nOut-degree of all leaf nodes=0");
            break;

        case 19:
            printf("Enter key");
            scanf("%d", &n);
            s = search(root, n);
            ln = maxValue(s->left);
            printf("Inorder predecessor of the key=%d", ln);
            break;

        case 20:
            count = 0;
            m = maxValue(root);
            printf("Max element=%d", m);
            break;

        case 21:
            count = 0;
            m = maxValue(root);
            printf("Number of edges=%d", count);
            break;

        case 22:
            exit(0);
        }
    }
}