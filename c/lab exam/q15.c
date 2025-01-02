// Write a menu driven C program to implement all operation of queue using array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Defining the maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to enqueue (add element to the queue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    if (q->front == -1) {  // If queue is empty, set front to 0
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove element from the queue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return an error code
    }

    int dequeuedValue = q->arr[q->front];
    if (q->front == q->rear) {  // If there was only one element
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return dequeuedValue;
}

// Function to peek (view the front element of the queue)
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;  // Return an error code
    }
    return q->arr[q->front];
}

// Function to display all elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function - Menu driven program
int main() {
    struct Queue q;
    int choice, value;

    // Initialize the queue
    initQueue(&q);

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Check if queue is empty\n");
        printf("6. Check if queue is full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;

            case 5:
                if (isEmpty(&q)) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 6:
                if (isFull(&q)) {
                    printf("Queue is full!\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
