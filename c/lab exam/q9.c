// Write a C Program for Evaluating the Postfix Expression: 3 8 + 9 8 / -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000

typedef struct stack
{
    int arr[max];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

void push(stack *s, int data)
{
    if (s->top == max - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

char pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

void evaluate(char *exp)
{
    stack s;
    init(&s);
    printf("Exp = ");
    puts(exp);

    for (int i = 0; i < strlen(exp); i++)
    {
        char ch = exp[i];
        printf("Ch = %c\n",ch);
        if (ch == ' ')
            continue;

         if (ch >= '0' && ch <= '9')
        {
            push(&s, ch - '0');
        }

        else
        {
            int op2 = pop(&s);
            int op1 = pop(&s);

            switch (ch)
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '^':
                push(&s, pow(op1, op2));
                break;
            case '/':
                if (op2 == 0)
                {
                    printf("Zero divison error\n");
                    break;
                }
                push(&s, op1 / op2);
                break;
            default:
                printf("Operator error\n");
            }
        }
    }
    printf("Result = %d", pop(&s));
}

int main()
{
    char exp[max];
    printf("Enter the expression : ");
    gets(exp);
    evaluate(exp);

    return 0;
}