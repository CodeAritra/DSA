#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = top;
    
    printf("%d pushed to stack\n", value);
    return newNode;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        exit(1);
    }
    
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    
    free(temp);
    printf("%d popped from stack\n", poppedValue);
    
    return top;
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* top = NULL;
    int choice=0, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                // printf("%d popped from stack\n", pop(top));
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } 

    return 0;
}