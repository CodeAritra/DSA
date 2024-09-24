#include<stdio.h>
#include<string.h>
#define max 100

char infix[max];
char postfix[max];
int index11 = 0;
char stack[max];
int top = -1;

int isEmpty(){
    if(top == -1) return 1;
    return 0;
}

void push(char data){
    top++;
    stack[top] = data;
}

char pop(){
    int ans = stack[top];
    top--;
    return ans;
}

int precedence(char ch){
    if (ch=='^') return 3;
    if(ch=='/' || ch=='*') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}

char associativity(char ch){
    if(ch=='^') return 'R';
    return 'L';
}

void infixToPostfix(char str[]){
    for(int i=0;i<strlen(str);i++){
        char ch = str[i];
        if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z') || (ch>=0&&ch<=9)){
            postfix[index11++] = ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(!isEmpty() && stack[top]!='('){
                postfix[index11++] = pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && (precedence(ch)<=precedence(stack[top])) && associativity(ch)=='L'){
                postfix[index11++] = pop();
            }
            push(ch);
        }
    }
    while(!isEmpty()){
        postfix[index11++]=pop();
    }
    printf("%s",postfix);
}

int main(){
    gets(infix);
    infixToPostfix(infix);

    return 0;
}