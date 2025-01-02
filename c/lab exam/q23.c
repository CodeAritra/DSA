/*A linked list contains some positive numbers and some negative numbers. Using this
linked list write a program in C to create two more linked lists, one containing all
positive numbers and another containing all negative numbers.*/

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

int main()
{
    struct Node *mainList = NULL;
    struct Node *posList = NULL;
    struct Node *negList = NULL;

    int n, data;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        mainList = appendNode(mainList, data);
    }
    
    printf("Original List:\n");
    printList(mainList);

    while (mainList != NULL)
    {
        if (mainList->data >= 0)
        {
            posList = appendNode(posList, mainList->data);
        }
        else
        {
            negList = appendNode(negList, mainList->data);
        }
        mainList = mainList->next;
    }

    printf("Positive List:\n");
    printList(posList);

    printf("Negative List:\n");
    printList(negList);

    return 0;
}
