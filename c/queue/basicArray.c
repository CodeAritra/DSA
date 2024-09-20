#include <stdio.h>
#define max 5

typedef struct queue
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

void enqueue(queue *q, int val)
{
    if (q->rear == max - 1)
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
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element : %d",q->arr[q->front]);
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
}

void display(queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
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

    int x = 1;
    int ch,val;

    while(x){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&val);
                enqueue(&q,val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                x = 0;
                break;
            default:
                printf("Wrong Input");
        }
    }

    return 0;
}