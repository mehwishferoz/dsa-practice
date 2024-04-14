//BST all operations
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *Node;
Node getnode(int key)
{
    Node newnode;
    newnode = (Node)malloc(sizeof(Node));
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    return newnode;
}
Node createtree(Node root,int key)
{
    if(root==NULL)
    {
        root=getnode(key);
        return root;
    }
    if(root->data>key)
    {
        root->left=createtree(root->left,key);
        return root;
    }
    if(root->data<key)
    {
        root->right=createtree(root->right,key);
        return root;
    }
}

Node searchtree(Node root, int key)
{
    if(root==NULL)
        return 0;
    if(root->data==key)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
        if(root->data<key)
        {
            root->right=searchtree(root->right, key);
            return root;
        }
        if(root->data>key)
        {
            root->left=searchtree(root->left, key);
            return root;
        }
    }
}
void inorder(Node root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int deletetree(Node root,int key)
{
    int flag;
    if(root==NULL)
        return 0;
    else if(root->data > key)
        flag=deletetree(root->left,key);
    else if(root->data < key)
        flag=deletetree(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return 1;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            Node temp=root;
            free(root);
            return 1;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            Node temp=root;
            free(root);
            return 1;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            int temp,max;
            max=findmax(root->left);
            root->data=max;
            flag=deletetree(root->left,max);
            return 1;
        }
        else
            return 0;
    }

}
int findmax(Node root)
{
   Node cur;
    cur=root;
    while(cur->right!=NULL)
    {
        cur=cur->right;
    }

    return cur->data;
}
void leaf(struct node *root, int level)
{
    if(root==NULL)
        return;
    if(root->left==NULL &&root->right==NULL)
        printf("%d ",root->data);
    leaf(root->left,level);
    leaf(root->right,level);
}

void printancestors(Node root,int key)
{
    if(root==NULL || root->data==key)
        return;
    if(key<root->data)
        printancestors(root->left,key);
    else
        printancestors(root->right,key);
    printf("%d ",root->data);
}

int heightoftree(Node root)
{
    int leftheight,rightheight;
    if(root==NULL)
        return 0;
    else
     {
        leftheight = heightoftree(root->left);
        rightheight = heightoftree(root->right);
        if(leftheight>rightheight)
        {
            return (leftheight+1);
        }
        else
        {
            return(rightheight+1);
        }
     }
}

void currentlevel(Node root, int level)
{
    if(root==NULL)
        return;
    if(level==1)
    {
        printf("%d ",root->data);
    }
    else if(level>1)
    {
        currentlevel(root->left,level-1);
        currentlevel(root->right,level-1);
    }
}

void levelorder(Node root)
{
    int h=heightoftree(root);
    int i;
    for(i=1;i<=h;i++)
    {
        currentlevel(root,i);
    }
}
 int levelnode(Node root,int key)
 {
     int c=0;
     while(root)
     {
         if(key>root->data)
         {
             c++;
             root=root->right;
         }
         else if(key<root->data)
         {
             c++;
             root=root->left;
         }
         else
         {
             printf("Level of node=%d\n",c);
             return 1;
         }

     }
     return 0;
 }

 void topview(Node root)
 {
     Node cur;
     cur=root;
     while(cur!=NULL)
     {
         printf("%d ",cur->data);
         cur=cur->left;
     }
     printf("%d ",root->data);
     cur=root->right;
     while(cur!=NULL)
     {
         printf("%d ",cur->data);
         cur=cur->right;
     }
 }

 void leftview(Node root)
 {
     Node cur;
     cur=root;
     while(cur!=NULL)
     {
         printf("%d ",cur->data);
         cur=cur->left;
     }
 }
 void rightview(Node root)
 {
     Node cur;
     cur=root;
     while(cur!=NULL)
     {
         printf("% ",cur->data);
         cur=cur->right;
     }
 }
main()
{
    int ch,key,key1,x,level,m,k,g;
    Node root=NULL;
    while(1)
    {
        printf("Enter\n1 to insert\n2 to delete\n3 to display\n4.to print leaf nodes\n5.to print ancestors\n6.Find level\n7.Height of tree\n8.level order\n9.Topview\n10.leftview\n11rightview\n12search\n13.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data\n");
                scanf("%d",&key);
                root=createtree(root,key);
                break;
            case 2:printf("Enter the data to be deleted\n");
                scanf("%d",&key1);
                x=deletetree(root,key1);
                if(x==0)
                    printf("Node not deleted\n");
                else //if(x==1)
                    printf("Node deleted\n");
              break;
            case 3:inorder(root);
                   break;
            case 4:leaf(root,level);
                   break;
            case 5:printf("Enter the node whose ancestors are to be printed\n");
                   scanf("%d",&key);
                   printf("Ancestors of %d are:",key);
                   printancestors(root,key);
                   break;
            case 6:printf("Enter the key whose level is to be found\n");
                   scanf("%d",&key);
                   m=levelnode(root,key);
                   if(m==1)
                   {
                       printf("Key found\n");
                   }
                   else
                   {
                       printf("Key not found\n");
                   }
                   break;
            case 7://printf("Enter the node whose height is to be found\n");
                   //scanf("%d",&key);
                   printf("Height of the tree is %d\n",heightoftree(root));
                   heightoftree(root);
                   break;
            case 8:levelorder(root);
                   break;
            case 9:topview(root);
                   break;
            case 10:leftview(root);
                    break;
            case 11:rightview(root);
                    break;
            case 12:printf("Enter the node to search\n");
                    scanf("%d",&k);
                    g=searchtree(root,k);
                    break;
            case 13:exit(0);
                   break;
        }
    }
}