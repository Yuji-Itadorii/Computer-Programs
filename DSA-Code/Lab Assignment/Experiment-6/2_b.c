#include <stdio.h>

#define SIZE 500

char stack[SIZE];
int size=SIZE;
int top=-1;

void push(char data){
    if(top==size-1){
        printf("Stack overflow\n");
    }
    top++;
    stack[top]=data;
}

void pop(){
    if(top==-1){
        printf("Stack underflow\n");
    }
    top--;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

char peek(){
    if(top==-1){
        return -1;
    }
    return stack[top];
}

void print(){
    for(int i=0; i<=top; i++){
        printf("%c ",stack[i]);
    }
}

int balancedParanthesis(char* str){
    int i=0;
    while(str[i]!='\0'){
        char ch=str[i];
        char top=peek();
        if(ch=='(' || ch=='{' || ch=='['){
            push(ch);
        }

        else if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']'))
        {
            pop();
        }
        else{
            return 0;
        }
        i++;
    }

    if(!isEmpty())
        return 0;

    else return 1;
}

int main(){
    char str[SIZE];
    printf("Enter the string\n");
    gets(str);
    if(balancedParanthesis(str)){
        printf("Paranthesis are balanced\n");
    }
    else{
        printf("Paranthesis are not balanced\n");
    }
    
}
