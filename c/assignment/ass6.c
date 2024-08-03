#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

struct node* insertAtBegin(struct node* head,int val){
    struct node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head,int val){
    struct node* newNode = createNode(val);
    struct node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = NULL;
    return head;
}

struct node* insertAtPos(struct node* head,int pos,int val){
    struct node* newnode = createNode(val);
    struct node* curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
    return head;
}

struct node* deleteFromBegin(struct node* head){
    return head->next;
}

struct node* deleteFromEnd(struct node* head){
    struct node* curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

struct node* deleteFromPos(struct node* head,int pos){
    struct node* curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}

void printLL(struct node* head){
    struct node* curr = head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr= curr->next;
    }
    printf("\n");
}


int main(){
    struct node* head = createNode(1);
    head = insertAtBegin(head,2);
    printLL(head);
    head = insertAtEnd(head,4);
    printLL(head);
    head = insertAtPos(head,2,9);
    printLL(head);
    // head = deleteFromBegin(head);
    // printLL(head);
    // head = deleteFromEnd(head);
    // printLL(head);
    head= deleteFromPos(head,3);
    printLL(head);

    return 0;
}