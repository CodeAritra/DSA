#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* constructTree() {
    int value, choice;
    printf("Enter value for the node (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct Node* newNode = createNode(value);
    printf("Enter left child of %d:\n", value);
    newNode->left = constructTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = constructTree();

    return newNode;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;

    printf("Construct the Binary Tree:\n");
    root = constructTree();

    while(1) {
        printf("\nMenu:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } 

    return 0;
}
