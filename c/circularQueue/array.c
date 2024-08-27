#include<stdio.h>
#define max 10

typedef struct{
    int arr[max];
    int front;
    int rear;
}cqueue;

void createCQueue(cqueue *cq){
    cq->front = -1;
    cq->rear = -1;
}

void cenqueue(cqueue *cq, int val){
    if((cq->rear+1)%max == cq->front){
        printf("Full\n");
        return;
    }

    if(cq->front == -1){
        cq->front = 0;
        cq->rear = 0;
        cq->arr[cq->rear] = val;
        return;
    }

    cq->rear = (cq->rear+1)%max;
    cq->arr[cq->rear] = val;
}

void cdequeue(cqueue *cq){
    if(cq->front == -1){
        printf("Empty\n");
        return;
    }

    if(cq->front > cq->rear){
        cq->front = cq->rear = -1;
        return;
    }

    printf("Dequeue = %d\n",cq->arr[cq->front]);
    cq->front = (cq->front+1)%max;
}

void display(cqueue *cq){
        int i;
        printf("Front -> %d \n", cq->front);
        printf("Items -> ");
        for (i = cq->front; i <= cq->rear; i = (i + 1) % max) {
            printf("%d ", cq->arr[i]);
        }
        
        printf("\nRear -> %d \n", cq->rear);
}

int main(){
    cqueue c; createCQueue(&c);

    cenqueue(&c,1);
    cenqueue(&c,2);
    cenqueue(&c,3);
    cenqueue(&c,4);
    cenqueue(&c,5);

    display(&c);

    cdequeue(&c);
    display(&c);

    cdequeue(&c);
    display(&c);

    cdequeue(&c);
    display(&c);

    cdequeue(&c);
    display(&c);

    cdequeue(&c);
    display(&c);

    cdequeue(&c);
    display(&c);
    
    cdequeue(&c);
    display(&c);

    return 0;
}