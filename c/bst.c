#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

node *createTree(node *root, int data)
{

    node *newnode = createNode(data);
    if (root == NULL)
        return newnode;

    if (data < root->data)
    {
        root->left = createTree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = createTree(root->right, data);
    }
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    node *root = NULL;

    int ch, data;

    while (1)
    {
        printf("\n1.Create Tree\n2.Inorder\n3.Preorder\n4.Postorder\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            root = createTree(root,data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        }
    }

    return 0;
}