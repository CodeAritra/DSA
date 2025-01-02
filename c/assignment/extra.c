// Program to implement Queue using Stack in C.
#include <stdio.h>
#define N 5
int stack1[5], stack2[5]; // declaration of two stacks
// declaration of top variables.
int top1 = -1, top2 = -1;
int count = 0;
// inserting the elements in stack1.
void push1(int data)
{
    // Condition to check whether the stack1 is full or not.
    if (top1 == N - 1)
    {
        printf("\n Stack is overflow...");
    }
    else
    {
        top1++;              // Incrementing the value of top1
        stack1[top1] = data; // pushing the data into stack1
    }
}
// Removing the elements from the stack1.
int pop1()
{
    // Condition to check whether the stack1 is empty or not.
    if (top1 == -1)
    {
        printf("\nStack is empty..");
    }
    else
    {
        int a = stack1[top1]; // Assigning the topmost value of stack1 to 'a' variable.
        top1--;               // decrementing the value of top1.
        return a;
    }
}
// pushing the data into the stack2.
void push2(int x)
{
    // Condition to check whether the stack2 is full or not
    if (top2 == N - 1)
    {
        printf("\nStack is full..");
    }
    else
    {
        top2++;           // incrementing the value of top2.
        stack2[top2] = x; // assigning the 'x' value to the Stack2
    }
}
// Removing the elements from the Stack2
int pop2()
{
    int element = stack2[top2]; // assigning the topmost value to element
    top2--;                     // decrement the value of top2
    return element;
}

void enqueue_d(int x)
{
    push1(x);
    count++;
}

void dequeue_d()
{
    if ((top1 == -1) && (top2 == -1))
    {
        printf("\nQueue is empty");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int element = pop1();
            push2(element);
        }
        int b = pop2();
        printf("\nThe dequeued element is %d", b);
        printf("\n");
        count--;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
    }
}

void enqueue_e(int x)
{

    while (top1 != -1)
    {
        push2(pop1());
    }
    push1(x);
    while (top2 != -1)
    {
        push1(pop2());
    }
}
// deleting the data from the Queue
void dequeue_e()
{
    int element = stack1[top1];
    top1--;
    printf("\nThe dequeued element is %d", element);
}
// displaying the data of the Queue
void display_e()
{
    if (top1 == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    for (int i = top1; i >= 0; i--)
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

void display_d()
{
    if (top1 == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");

}

void main()
{
    int data, ch1, ch2, x;
    while (1)
    {
        x = 1;
        printf("1. Dequeue Costly\n2. Enqueue Costly\nEnter your choice : ");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            while (x)
            {
                printf("1. Enqueue \n2. Dequeue \n3. Display\n4. Exit\nEnter your choice : ");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    printf("Enter data : ");
                    scanf("%d", &data);
                    enqueue_d(data);
                    break;
                case 2:
                    dequeue_d();
                    break;
                case 3:
                    display_d();
                    break;
                case 4:
                    x = 0;
                    break;
                default:
                    printf("Wrong input");
                }
            }
            break;
        case 2:
            while (x)
            {
                printf("1. Enqueue \n2. Dequeue \n3. Display\n4. Exit\nEnter your choice : ");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    printf("Enter data : ");
                    scanf("%d", &data);
                    enqueue_e(data);
                    break;
                case 2:
                    dequeue_e();
                    break;
                case 3:
                    display_e();
                    break;
                case 4:
                    x = 0;
                    break;
                default:
                    printf("Wrong input");
                }
            }
            break;

        default:
            printf("Wrong input");
        }
    }
}