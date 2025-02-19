#include <stdio.h>
#define max 5

typedef struct cqueue
{
    int arr[max];
    int front;
    int rear;
} cqueue;

void init(cqueue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(cqueue *q)
{
    int data;
    printf("Enter data : ");
    scanf("%d", &data);

    if ((q->rear + 1) % max == q->front)
    {
        printf("Overflow\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % max;
    q->arr[q->rear] = data;
    printf("Enqueued element : %d\n", q->arr[q->rear]);
}

void dequeue(cqueue *q)
{
    if (q->front == -1)
    {
        printf("Undeflow\n");
        return;
    }

    printf("Dequeued element : %d\n", q->arr[q->front]);
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % max;
}

void display(cqueue *q)
{
    if (q->front == -1)
    {
        printf("Undeflow\n");
        return;
    }
    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % max;
    }
}

int main()
{
    cqueue c;
    init(&c);

    int ch, x = 1;

    while (x)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&c);
            break;
        case 2:
            dequeue(&c);
            break;
        case 3:
            display(&c);
            break;
        default:
            printf("Wrong\n");
        }
    }

    return 0;
}