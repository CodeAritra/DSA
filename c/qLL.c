#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("%d enqueued to queue\n", value);
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
    
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow - The queue is empty\n");
        return -1;
    }
    
    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    
    return dequeuedValue;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node* temp = q->front;
    printf("Queue elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    
    int choice = 0, value;

    while (choice != 4) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                    printf("%d dequeued from queue\n", value);
                break;
            case 3:
                display(q);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}