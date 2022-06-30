#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct stack
{
    int capacity;
    int *arr;
    int top;
};

struct stack *createStack(int x)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->capacity = x;
    s->arr = (int *)malloc(sizeof(int) * s->capacity);
    return s;
}

bool isFull(struct stack *s)
{
    return (s->top == (s->capacity - 1));
}

bool isEmpty(struct stack *s)
{
    return (s->top == -1);
}

void push(struct stack *s, int x)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Empty!!\n");
        return INT_MAX;
    }

    int res = s->arr[s->top];
    s->top--;
    return res;
}

int peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Empty!!\n");
        return INT_MAX;
    }
    return s->arr[s->top];
}

int size(struct stack *s){
    return (s->top+1);
}

void display(struct stack * s){
    int x = size(s);
    for (int i = 0; i < x; i++)
    {
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main()
{

    struct stack * s = createStack(5);

    push(s , 10);
    push(s , 20);
    push(s , 30);

    display(s);
    printf("%d\n",size(s));
    pop(s);

    display(s);
    printf("%d\n",size(s));

    printf("%d\n",peek(s));

    return 0;
}