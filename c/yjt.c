#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

node *insertAtBegining(node *head, int val)
{
    node *newnode = createNode(val);
    if (head == NULL)
        return newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

node *insertAtEnd(node *head, int val)
{
    node *newnode = createNode(val);
    if (head == NULL)
        return newnode;
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    return head;
}

node *insertAtPos(node *head, int val, int pos)
{
    node *newnode = createNode(val);
    if (head == NULL)
        return newnode;
    node *curr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
    return head;
}

node *deleteBegin(node *head)
{
    if (head == NULL)
    {
        printf("underflow");
        return head;
    }
    node *temp = head->next;
    free(head);
    return temp;
}

node *deleteEnd(node *head)
{
    if (head == NULL)
    {
        printf("underflow");
        return head;
    }
    node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = NULL;
    free(temp);
    return head;
}

node *deletePos(node *head, int pos)
{
    if (head == NULL)
    {
        printf("underflow");
        return head;
    }
    node *curr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

void printLL(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;

    int x = 1;
    int ch;

    while(x){
        printf("\n1. Insert ata begin\n2. Insert at end\n3. Insert at any position\n4. Delete from begin\n5. Delete from end\n6. ")
    }

    return 0;
}