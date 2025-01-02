// Write a C program to check a single link list is palindrome or not.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
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

// Function to print the linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1; // Empty or single element list is a palindrome
    }

    // Step 1: Find the middle of the linked list
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    struct Node *secondHalf = reverseList(slow);
    struct Node *firstHalf = head;

    printf("First : ");
    printList(firstHalf);
    printf("second : ");
    printList(secondHalf);

    // Step 3: Compare both halves
    while (secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            return 0; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1; // Palindrome
}

int main()
{
    struct Node *head = NULL;
    int n, data;

    // Input the number of elements in the list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    // Input the elements of the list
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = appendNode(head, data);
    }

    // Print the linked list
    printf("The linked list is:\n");
    printList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        printf("The linked list is a palindrome.\n");
    }
    else
    {
        printf("The linked list is NOT a palindrome.\n");
    }

    return 0;
}
