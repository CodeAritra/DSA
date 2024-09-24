#include <stdio.h>
#define max 4

typedef struct
{
    int arr[max];
    int front;
    int rear;
} cqueue;

void createCQueue(cqueue *cq)
{
    cq->front = -1;
    cq->rear = -1;
}

void cenqueue(cqueue *cq, int val)
{  
    if ((cq->rear + 1) % max == cq->front)
    {
        printf("Overflow\n");
        return;
    }

    if (cq->front == -1)
    {
        cq->front = 0;
        cq->rear = 0;
        cq->arr[cq->rear] = val;
        return;
    }

    cq->rear = (cq->rear + 1) % max;
    cq->arr[cq->rear] = val;
}

void cdequeue(cqueue *cq)
{
    if (cq->front == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Dequeue = %d\n", cq->arr[cq->front]);

     if (cq->front == cq->rear)
     {
         cq->front = cq->rear = -1;
         return;
     }

    cq->front = (cq->front + 1) % max;
}

void display(cqueue *cq)
{
    int i;
    if (cq->front == -1)
    {
        //  printf("\nfront = %d, rear = %d\n", cq->front, cq->rear);
        
        printf("Underflow\n");
        return;
    }
      printf("Items -> ");
    if (cq->rear >= cq->front)
    {
        //  printf("\nfront = %d, rear = %d\n", cq->front, cq->rear);
        for (i = cq->front; i <= cq->rear; i++)
        {
            printf("%d ", cq->arr[i]);
        }
    }
    else
    {
        //  printf("\nfront = %d, rear = %d\n", cq->front, cq->rear);

        for (i = cq->front; i < max; i++)
        {
            printf("%d ", cq->arr[i]);
        }
        for (i = 0; i <= cq->rear; i++)
        {
            printf("%d ", cq->arr[i]);
        }
    }
}

int main()
{
    cqueue c;
    createCQueue(&c);

    int x = 1;
    int ch, val;

    while (x)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &val);
            cenqueue(&c, val);
            break;
        case 2:
            cdequeue(&c);
            break;
        case 3:
            display(&c);
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