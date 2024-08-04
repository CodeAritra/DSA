#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct
{
    node *top;
} stack;

int isEmpty(stack *s)
{
    return s->top == NULL;
}

void createStack(stack *s)
{
    s->top = NULL;
}

void push(stack *s, int val)
{
    struct node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = s->top;
    s->top = newnode;
}

void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty");
        return;
    }
    s->top = s->top->next;
}

int peek(stack *s){
    return s->top->data;
}

int main()
{
    stack s;
    createStack(&s);
    push(&s,5);
    push(&s,6);
    push(&s,7);

    printf("%d",peek(&s));
    pop(&s);
    printf("%d",peek(&s));

    return 0;
}