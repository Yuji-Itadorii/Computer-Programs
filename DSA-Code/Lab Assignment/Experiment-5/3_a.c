#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int data;
    struct node * next;
};

struct stack
{
    int size;
    int capacity ;
    struct node * head;
};

struct stack * createStack(int x)
{
    struct stack * s ;
    s->head = NULL;
    s->capacity = x;
    s->size = 0;
    printf("->");
    return s;
}

bool isEmpty(struct stack *s)
{
    return (s->head==NULL);
}

bool isFull(struct stack *s)
{
    return (s->size == (s->capacity-1));
}

struct stack * push(struct stack *s, int x)
{
    struct node * newNode = (struct node * )malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = s->head;
    s->head = newNode;
    s->size = s->size + 1; 
    return  s ;
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Empty!!\n");
        return INT_MAX;
    }
    struct node  * temp = s->head;
    int res = s->head->data;
    s->head = s->head->next;
    free(temp);
    s->size--;
    return res ;
}

int peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Empty!!\n");
        return INT_MAX;
    }
    return s->head->data;
}

int size(struct stack *s){
    return s->size;
}

void display(struct stack * s){
    struct node * temp = s->head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    struct stack * s = createStack(5);

    s = push(s , 10);
    s = push(s , 20);
    s = push(s , 30);

    display(s);
    printf("%d\n",size(s));
    pop(s);

    display(s);
    printf("%d\n",size(s));

    printf("%d\n",peek(s));

    return 0;
}