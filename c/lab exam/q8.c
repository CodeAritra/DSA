// Write a C program to transform the following infix expression to postfix expression:(A+B^D)*(D/E)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct stack
{
    char arr[max];
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

int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    stack s;
    init(&s);

    int j = 0;


    for (int i = 0; i < strlen(infix); i++)
    {

        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }

        else if (ch == '(')
        {
            push(&s, ch);
        }

        else if (ch == ')')
        {
            while (s.top != -1 && s.arr[s.top] != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }

        else
        {
            while (s.top != -1 && precedence(ch) <= precedence(s.arr[s.top]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (s.top != -1)
    {
        postfix[j++] = pop(&s);
    }
    printf("Postfix : ");
    puts(postfix);
}

int main()
{
    char infix[max], postfix[max];

    printf("Enter the infix : ");
    gets(infix);

    infixToPostfix(infix, postfix);

    // puts(postfix);;

    return 0;
}