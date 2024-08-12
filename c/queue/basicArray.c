#include <stdio.h>
#define max 5

typedef struct
{
    int arr[max];
    int front;
    int rear;
} queue;

void createQueue(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

int isFull(queue *q)
{
    if (q->rear == max - 1)
        return 1;
    return 0;
}

void enqueue(queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++(q->rear)] = val;
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
}

int peek(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(queue *q)
{
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);


    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);

    printf("Front element is: %d\n", peek(&q));

    return 0;
}