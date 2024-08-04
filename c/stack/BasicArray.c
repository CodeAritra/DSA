#include <stdio.h>
#define max 100

typedef struct
{
    int top;
    int arr[max];
} stack;

void createStack(stack *s)
{
    s->top = -1;
}

int isFull(stack *s)
{
    return s->top == max - 1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow");
        return;
    }
    s->arr[++(s->top)] = val;
}

void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow");
        return;
    }
    s->arr[(s->top)--];
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow");
        return -1;
    }
    return s->arr[s->top];
}

int main()
{
    stack s;
    createStack(&s);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);

    printf("%d", peek(&s));
    pop(&s);
    printf("%d", peek(&s));

    return 0;
}