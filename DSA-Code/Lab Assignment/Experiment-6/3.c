#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int size=SIZE;
int top_front=-1;
int top_back=SIZE;

void push_front(int data){
    if(top_front==size-1 || top_front==top_back-1){
        printf("Stack overflow\n");
        return;
    }
    top_front++;
    stack[top_front]=data;
}

void push_back(int data){
    if(top_back==0 || top_front==top_back-1){
        printf("Stack overflow\n");
        return;
    }
    
    top_back--;
    stack[top_back]=data;
}

void pop_front(){
    if(top_front==-1){
        printf("Stack underflow\n");
        return;
    }
    top_front--;
}

void pop_back(){
    if(top_back==size){
        printf("Stack overflow\n");
        return;
    }
    top_back++;
}

int isFull(){
    if(top_front==size-1 || top_back==0 || top_front==top_back-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top_back==size || top_front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void print(){
    for(int i=0; i<=size-1; i++){
        printf("%d ",stack[i]);
    }
}

int main(){
    push_front(56);
    push_front(42);
    push_back(34);
    push_back(23);
    push_front(54);
    push_back(23);

    return 0;
}
