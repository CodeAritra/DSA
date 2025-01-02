// Write a C program to compare two linked lists are identical or not.

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

int isidentical(struct Node *l1, struct Node *l2)
{
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data != l2->data)
            return 0;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == NULL && l2 == NULL)
        return 1;

    return 0;
}

int main()
{
    struct Node *l1 = NULL;
    struct Node *l2 = NULL;

    int n1, n2, data;

    printf("Enter the number of elements in the list 1 : ");
    scanf("%d", &n1);

    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &data);
        l1 = appendNode(l1, data);
    }

    printf("Enter the number of elements in the list 2: ");
    scanf("%d", &n2);

    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        l2 = appendNode(l2, data);
    }

    printf("List 1 :\n");
    printList(l1);
    printf("List 2 :\n");
    printList(l2);

    if (isidentical(l1, l2))
    {
        printf("The two linked lists are identical.\n");
    }
    else
    {
        printf("The two linked lists are not identical.\n");
    }
}