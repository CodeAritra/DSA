#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* top) {
    return (top == NULL);
}

struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;  
    printf("%d pushed to the stack.\n", data);
    return newNode;  
}

struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty. Cannot pop.\n");
        return top;
    }
    struct Node* temp = top;
    printf("%d popped from the stack.\n", top->data);
    top = top->next;  
    free(temp);  
    return top;  
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}


int main() {
    struct Node* top = NULL; 

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);


    printf("Top element is: %d\n", peek(top));

 
    top = pop(top);
    top = pop(top);

   
    printf("Top element is: %d\n", peek(top));

   
    top = pop(top);

   
    if (isEmpty(top))
        printf("Stack is empty now.\n");

    return 0;
}
