// Write a C program to remove duplicates from a sorted single linked list.

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node *insert(node *head, int data)
{
    node *newnode = createNode(data);
    node *curr = head;
    if (head == NULL)
    {
        return newnode;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    return head;
}

void removeDuplicates(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
}

void printLL(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    // node *head = createNode(1);
    // head->next = createNode(2);
    // head->next->next = createNode(2);
    // head->next->next->next = createNode(3);
    // head->next->next->next->next = createNode(3);
    // head->next->next->next->next->next = createNode(4);
    // printf("Original : ");
    // printLL(head);
    // removeDuplicates(head);
    // printLL(head);

    node *head = NULL;
    int ch, val, x = 1;
    while (x)
    {
        printf("1.Insert\n2.Remove Duplicates\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &val);
            head = insert(head, val);
            break;
        case 2:
            removeDuplicates(head);
            break;
        case 3:
            printLL(head);
            break;
        case 4:
            x = 0;
            break;
        default:
            printf("Wrong Input");
        }
    }
}