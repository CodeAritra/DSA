//5) Write a C program to implement the ENQUEUE operation of a queue using single linked list.
//11) Write a C program to implement the DEQUEUE of a queue operation using single linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
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

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);

    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        queue->front = queue->rear = newNode;
        printf("Enqueued %d into the queue.\n", data);
        return;
    }

    // Otherwise, add the new node at the rear and update the rear pointer
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d into the queue.\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow! No elements to dequeue.\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    struct Node* temp = queue->front; // Temporarily store the front node
    int dequeuedData = temp->data; // Get the data of the front node
    queue->front = temp->next; // Update the front pointer to the next node

    // If the front becomes NULL, the queue is empty, so update rear as NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
    printf("Dequeued %d from the queue.\n", dequeuedData);
    return dequeuedData;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Queue* queue = createQueue();

    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
