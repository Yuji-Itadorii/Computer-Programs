#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("\n");
}

int isOperator(char ch){
    char str[]="+-*/^(){}[]";
    int i=0;
    while(str[i]!='\0'){
        if(ch==str[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+'|| ch=='-'){
        return 1;
    }
}

int associativity(char ch){
    if(ch=='*' || ch=='/' || ch=='+'|| ch=='-'){
        return 1;
    }
    else if(ch=='^'){
        return 2;
    }
}

char* infix_to_postfix(char* str){
    int len=strlen(str);
    for(int i=0; i<len/2; i++){
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
    printf("%s\n",str);

    char* postfix=(char*)malloc((sizeof(char)*strlen(str))+1);
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(!isOperator(str[i])){
            postfix[j]=str[i];
            i++;
            j++;
        }
        else if(isEmpty() || peek()==')'){
            push(str[i++]);
        }
        else if(str[i]==')'){
            push(str[i]);
            i++;
        }
        else if(str[i]=='('){
            while(!isEmpty() && peek()!=')'){
                postfix[j++]=peek();
                pop();
            }
            pop();
            i++;
        }
        else if(precedence(str[i])>precedence(peek())){
            push(str[i]);
            i++;
        }
        else if(precedence(str[i])<precedence(peek())){
            
            char ch=peek();
            pop();
            postfix[j]=ch;
            j++;
        }
        else if(precedence(str[i])==precedence(peek())){
            if(associativity(str[i])==2){
                char ch=peek();
                pop();
                postfix[j]=ch;
                push(str[i]);
                i++;
                j++;
            }
            else{
                push(str[i]);
                i++;
            }
        }
    }

    while(!isEmpty()){
        postfix[j]=peek();
        pop();
        j++;
    }
    postfix[j]='\0';
    len=strlen(postfix);
    for(int i=0; i<len/2; i++){
        char temp=postfix[i];
        postfix[i]=postfix[len-i-1];
        postfix[len-i-1]=temp;
    }

    return postfix;
}
int main(){
    char str[SIZE];
    printf("Enter the string\n");
    gets(str);
    // printf("%s",str);
    char* postfix=infix_to_postfix(str);
    printf("%s",postfix);
    
    return 0;
}
