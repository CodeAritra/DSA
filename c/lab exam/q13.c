// Write a menu driven C program to implement all operation of stack using array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Defining the maximum size of the stack

// Stack structure with an array and a top index
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Initially, the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    if (stack->top == MAX - 1)
        return 1; // Stack is full
    return 0;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    if (stack->top == -1)
        return 1; // Stack is empty
    return 0;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", data);
        return;
    }
    stack->arr[++(stack->top)] = data;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! No element to pop.\n");
        return -1; // Return -1 to indicate the stack is empty
    }
    int poppedData = stack->arr[(stack->top)--];
    printf("Popped %d from the stack.\n", poppedData);
    return poppedData;
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No element to peek.\n");
        return -1; // Return -1 to indicate the stack is empty
    }
    return stack->arr[stack->top];
}

// Function to display the elements of the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack stack;
    initStack(&stack); // Initialize the stack
    int choice, value;

    do {
        printf("\nStack Operations using Array:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Check if Stack is Empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                displayStack(&stack);
                break;
            case 5:
                if (isFull(&stack)) {
                    printf("Stack is Full.\n");
                } else {
                    printf("Stack is not Full.\n");
                }
                break;
            case 6:
                if (isEmpty(&stack)) {
                    printf("Stack is Empty.\n");
                } else {
                    printf("Stack is not Empty.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
