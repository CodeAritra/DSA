/*There are two linked lists L1 and L2 containing the following data:
L1: 3, 7,10,15,16,9,22,17,32
L2: 16,2,9,13,47,8,10,1,28
Write a C program to create a linked list L3 that contains only those elements that are
common in linked list L1 and L2.*/

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

void appendNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to check if an element is present in the list
int isPresent(struct Node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
        {
            return 1; // Data found
        }
        head = head->next;
    }
    return 0; // Data not found
}

// Function to create a new list containing common elements from L1 and L2
void createCommonList(struct Node *L1, struct Node *L2, struct Node **L3)
{
    struct Node *temp = L1;
    while (temp != NULL)
    {
        // If the element is present in both L1 and L2, append it to L3
        if (isPresent(L2, temp->data))
        {
            appendNode(L3, temp->data);
        }
        temp = temp->next;
    }
}

// Function to print a linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory of a linked list
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *L1 = NULL;
    struct Node *L2 = NULL;
    struct Node *L3 = NULL;

    // Elements of L1
    int L1_data[] = {3, 7, 10, 15, 16, 9, 22, 17, 32};
    int L1_size = sizeof(L1_data) / sizeof(L1_data[0]);

    // Elements of L2
    int L2_data[] = {16, 2, 9, 13, 47, 8, 10, 1, 28};
    int L2_size = sizeof(L2_data) / sizeof(L2_data[0]);

    // Creating the linked list L1
    for (int i = 0; i < L1_size; i++)
    {
        appendNode(&L1, L1_data[i]);
    }

    // Creating the linked list L2
    for (int i = 0; i < L2_size; i++)
    {
        appendNode(&L2, L2_data[i]);
    }

    // Create L3 containing common elements of L1 and L2
    createCommonList(L1, L2, &L3);

    // Print the original lists and the common list L3
    printf("List L1:\n");
    printList(L1);

    printf("List L2:\n");
    printList(L2);

    printf("Common List L3:\n");
    printList(L3);

    // Free the memory allocated for all lists
    freeList(L1);
    freeList(L2);
    freeList(L3);

    return 0;
}
