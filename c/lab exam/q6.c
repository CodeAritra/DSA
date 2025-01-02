// Write a C program to check whether the given string is Palindrome or not using Stack.

#include <stdio.h>
#include <string.h>
#define max 10000

typedef struct stack
{
    char arr[max];
    int top;
} stack;

void init(stack *st)
{
    st->top = -1;
}

void push(stack *st, char data)
{
    if (st->top == max - 1)
    {
        printf("Overflow\n");
        return;
    }
    st->arr[++st->top] = data;
}

char pop(stack *st)
{
    if (st->top == -1)
    {
        printf("Underflow\n");
        return '\0';
    }
    return st->arr[st->top--];
}

int isPalindrome(char str[])
{
    stack st;
    init(&st);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(&st, str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if(str[i] != pop(&st)){
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[max];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string %s is palindrome.\n", str);
    } else {
        printf("The string %s is not palindrome.\n", str);
    }

    return 0;
}
