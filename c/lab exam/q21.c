// Write a C Program to add two Polynomials using Single Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node *next;
} node;

node *createNode(int coeff, int pow)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    return newnode;
}

node *appendNode(node *poly, int coeff, int pow)
{
    node *newnode = createNode(coeff, pow);

    if(poly == NULL || poly->pow < pow){
        newnode->next = poly;
        poly = newnode;
        return poly;
    }

    node *curr = poly;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    return poly;
}

void printPoly(node *poly)
{
    if (poly == NULL)
    {
        printf("Nothing to print");
        return;
    }

    node *curr = poly;
    while (curr != NULL)
    {
        printf("%d^%d", curr->coeff, curr->pow);
        if (curr->next != NULL)
        {
            printf(" + ");
        }
        curr = curr->next;
    }
    printf("\n");
}

node *addPolynomials(node *poly1, node *poly2)
{
    node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            result = appendNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly2->pow > poly1->pow)
        {
            result = appendNode(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else
        {
            result = appendNode(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        result = appendNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        result = appendNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    node *result = NULL;

    int coeff, pow, choice, terms, x = 1;

    while (1)
    {
        printf("\nPolynomial Operations Menu:\n");
        printf("1. Input Polynomial 1\n");
        printf("2. Input Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Polynomial 1\n");
        printf("5. Display Polynomial 2\n");
        printf("6. Display Resultant Polynomial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of terms for Polynomial 1: ");
            scanf("%d", &terms);
            for (int i = 0; i < terms; i++)
            {
                printf("Enter coefficient and power for term %d: ", i + 1);
                scanf("%d %d", &coeff, &pow);
                poly1 = appendNode(poly1, coeff, pow);
            }
            printf("Polynomial 1 successfully added.\n");
            break;

        case 2:
            printf("Enter the number of terms for Polynomial 2: ");
            scanf("%d", &terms);
            for (int i = 0; i < terms; i++)
            {
                printf("Enter coefficient and power for term %d: ", i + 1);
                scanf("%d %d", &coeff, &pow);
                poly2 = appendNode(poly2, coeff, pow);
            }
            printf("Polynomial 2 successfully added.\n");
            break;

        case 3:
            result = addPolynomials(poly1, poly2);
            printf("Polynomials added successfully.\n");
            break;

        case 4:
            printf("Polynomial 1: ");
            printPoly(poly1);
            break;

        case 5:
            printf("Polynomial 2: ");
            printPoly(poly2);
            break;

        case 6:
            printf("Resultant Polynomial: ");
            printPoly(result);
            break;

        case 7:
            x = 0;
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}