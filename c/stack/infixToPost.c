#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

char stack[max];
int top = -1;
char result[100];
int resultIndex = 0;

int isFull()
{
    if (top == max - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push(char data)
{
    stack[++top] = data;
}

char pop()
{
    int ans = stack[top];
    top--;
    return ans;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L';
}

char infixToPostfix(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 0 && ch <= 9))
        {
            result[resultIndex++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                result[resultIndex++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && (precedence(ch) <= precedence(stack[top])) && associativity(ch) == 'L')
            {
                result[resultIndex++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty())
    {
        result[resultIndex++] = pop();
    }

    // result[++resultIndex] = '\0';
    printf("%s\n", result);
}

int main()
{
    char exp[max];
    printf("Enter a string : ");
    gets(exp);

    printf("Postfix : ");
    infixToPostfix(exp);
    return 0;

    // a+b*(c^d-e)^(f+g*h)-i
    // abcd^e-fgh*+^*+i-
}