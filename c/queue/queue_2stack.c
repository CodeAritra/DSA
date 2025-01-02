#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack
{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

void push(Stack *stack, int data)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void enqueue(Stack *stack1, int data)
{
    push(stack1, data);
}

int dequeue(Stack *stack1, Stack *stack2)
{
    if (stack2->top == -1)
    {
        while (stack1->top != -1)
        {
            push(stack2, pop(stack1));
        }
    }
    return pop(stack2);
}

void display(Stack *stack1, Stack *stack2)
{
    if (stack1->top == -1 && stack2->top == -1)
    {
        printf("Underflow\n");
        return;
    }

    printf("Queue contents: ");

    for (int i = stack2->top; i >= 0; i--)
    {
        printf("%d ", stack2->arr[i]);
    }

    for (int i = 0; i <= stack1->top; i++)
    {
        printf("%d ", stack1->arr[i]);
    }

    printf("\n");
}

int main()
{
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    int choice, value;

    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&stack1, value);
            printf("%d enqueued successfully.\n", value);
            break;

        case 2:
            if ((&stack1)->top == -1 && (&stack2)->top == -1)
            {
                printf("Underflow\n");
            }
            else
            {
                value = dequeue(&stack1, &stack2);
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            display(&stack1, &stack2);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
