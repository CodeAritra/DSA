#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* front) {
    return (front == NULL);
}


struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        printf("%d enqueued to the queue.\n", data);
        return newNode;
    }
    rear->next = newNode;
    printf("%d enqueued to the queue.\n", data);
    return newNode;
}

struct Node* dequeue(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return front;
    }
    struct Node* temp = front;
    front = front->next;  
    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);  
    return front;  
}


int peek(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return front->data;
}


int main() {
    struct Node* front = NULL;  
    struct Node* rear = NULL;   


    rear = enqueue(rear, 10);
    if (front == NULL) front = rear;  

    rear = enqueue(rear, 20);
    rear = enqueue(rear, 30);


    printf("Front element is: %d\n", peek(front));


    front = dequeue(front);
    if (front == NULL) rear = NULL;

    front = dequeue(front);
    if (front == NULL) rear = NULL; 
   
    printf("Front element is: %d\n", peek(front));

    
    front = dequeue(front);
    if (front == NULL) rear = NULL;  

    if (isEmpty(front))
        printf("Queue is empty now.\n");

    return 0;
}
