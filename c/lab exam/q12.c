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

// Function to split the list into Even and Odd lists
// void splitEvenOdd(struct Node* head, struct Node** evenList, struct Node** oddList) {
//     while (head != NULL) {
//         if (head->data % 2 == 0) {
//             appendNode(evenList, head->data);
//         } else {
//             appendNode(oddList, head->data);
//         }
//         head = head->next;
//     }
// }

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

int main()
{
    struct Node *mainList = NULL;
    struct Node *evenList = NULL;
    struct Node *oddList = NULL;

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

    // Split the list into Even and Odd lists
    // splitEvenOdd(mainList, &evenList, &oddList);

    while (mainList != NULL)
    {
        if (mainList->data % 2 == 0)
        {
            evenList = appendNode(evenList, mainList->data);
        }
        else
        {
            oddList = appendNode(oddList, mainList->data);
        }
        mainList = mainList->next;
    }

    printf("Even List:\n");
    printList(evenList);

    printf("Odd List:\n");
    printList(oddList);

    return 0;
}
