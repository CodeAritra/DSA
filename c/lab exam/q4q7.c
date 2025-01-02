//4) Write a C program to implement the PUSH operation of a stack using single linked list.
// 7) Write a C program to implement the POP operation of a stack using single linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top; // Point the new node to the current top
    top = newNode;       // Update the top pointer
    printf("Pushed %d onto the stack.\n", data);
    return top;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack underflow! No elements to pop.\n");
        return top; // Return -1 to indicate the stack is empty
    }

    struct Node* temp = top; // Temporarily store the current top
    int poppedData = temp->data; // Get the data of the top node
    top = temp->next; // Update the top pointer to the next node
    free(temp); // Free the memory of the popped node
    printf("Popped %d from the stack.\n", poppedData);
    return top;
}

// Function to display the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* stack = NULL; // Initialize stack as empty

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                stack = push(stack, value);
                break;
            case 2:
                stack = pop(stack);
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    while (stack != NULL) {
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
