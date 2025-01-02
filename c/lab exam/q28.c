#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *appendNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void combine(struct Node *A, struct Node *B)
{
    struct Node *currentA = A;
    struct Node *currentB = B;

    while (currentA != NULL && currentB != NULL)
    {
        struct Node *nextA = currentA->next;
        struct Node *nextB = currentB->next;

        currentA->next = currentB;
        currentB->next = nextA;

        currentA = nextA;
        currentB = nextB;
    }
}

int main()
{
    struct Node *A = NULL;
    struct Node *B = NULL;

    int n, data;

    printf("Enter the number of elements in List A: ");
    scanf("%d", &n);
    printf("Enter %d elements for List A:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        A = appendNode(A, data);
    }

    printf("Enter the number of elements in List B: ");
    scanf("%d", &n);
    printf("Enter %d elements for List B:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        B = appendNode(B, data);
    }

    printf("List A:\n");
    printList(A);
    printf("List B:\n");
    printList(B);

    combine(A, B);

    printf("Combined List:\n");
    printList(A);

    return 0;
}
