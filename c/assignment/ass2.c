#include <stdio.h>
#define cap 100

typedef struct {
    int arr[cap];
    int top;
}stack;

void createStack(stack *s){
    s->top = -1;
}

void push(stack *s,int val){
    if(s->top == cap-1){
        printf("Stack Overflow");
        return;
    }

    s->arr[++(s->top)] = val;
}

void pop(stack *s){
    if(s->top == -1){
        printf("Stack underflow");
        return;
    }
    printf("Popped element = %d",s->arr[s->top]);
    (s->top)--;
}

void display(stack *s){
    if(s->top == -1){
        printf("Stack is empty");
        return;
    }
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
}

int main(){
    stack s;
    createStack(&s);

    int choice,val,x=1;

    while(x){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter a choice : \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&val);
                push(&s,val);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                x = 0;
                break;
            default:
                printf("Wrong Input");
        }
    }

    return 0;
}
