#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char result[100];
    char stack[100];
    int stackIndex = -1;
    int resultIndex = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 0 && ch <= 9))
        {
            result[resultIndex++] = ch;
        }
        else if (ch == '(')
        {
            stack[++stackIndex] = ch;
        }
        else if (ch == ')')
        {
            while (stackIndex >= 0 && stack[stackIndex] != '(')
            {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--;
        }
        else
        {
            while (stackIndex >= 0 && (precedence(ch) <= precedence(stack[stackIndex])) && associativity(ch) == 'L')
            {
                result[resultIndex++] = stack[stackIndex--];
            }
           stack[++stackIndex] = ch;
        }
    }

    while (stackIndex >= 0)
    {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

    infixToPostfix(exp);
    return 0;

    //abcd^e-fgh*+^*+i-
}