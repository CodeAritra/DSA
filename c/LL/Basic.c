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

     if(head == NULL) return newNode;

    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head,int val){
    struct node* newNode = createNode(val);

    if(head == NULL) return newNode;

    struct node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

struct node* insertAtPos(struct node* head,int pos,int val){
    struct node* newnode = createNode(val);

    if(head == NULL) return newnode;

    struct node* curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
    return head;
}

struct node* deleteFromBegin(struct node* head){
    if(head == NULL){
        return head;
    } 

    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteFromEnd(struct node* head){
    if(head == NULL){
        return head;
    } 

    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }

    struct node* curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }

    struct node* temp = curr->next;
    curr->next = NULL;
    free(temp);
    return head;
}

struct node* deleteFromPos(struct node* head,int pos){
    if(head == NULL){
        return head;
    } 

     if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }

    struct node* curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }
    struct node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

void printLL(struct node* head){
    if(head == NULL){
        printf("Underflow");
        return;
    } 

    struct node* curr = head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr= curr->next;
    }
    printf("NULL\n");
}


int main(){
    struct node* head = NULL;

    int choice,val,pos,x=1;

    while(x){
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Delete from beginning\n5. Delete from end\n6. Delete from any position\n7. Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&val);
                head = insertAtBegin(head,val);
                printLL(head);
                break;
            case 2:
                printf("Enter the value : ");
                scanf("%d",&val);
                head = insertAtEnd(head,val);
                printLL(head);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d",&pos);
                printf("Enter the value : ");
                scanf("%d",&val);
                head = insertAtPos(head,pos,val);
                printLL(head);
                break;
            case 4:
                head = deleteFromBegin(head);
                printLL(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                printLL(head);
                break;
            case 6:
                if(head!=NULL){
                    printf("Enter the position : ");
                    scanf("%d",&pos);
                    head = deleteFromPos(head,pos);
                    printLL(head);
                }
                else{
                    printLL(head);
                }
                break;
            case 7:
                x=0;
                break;
            default:
                printf("Wrong Input");
        }
    }

    return 0;
}