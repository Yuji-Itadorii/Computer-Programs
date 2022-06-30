#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int capacity;
    char *arr;
    int top;
};

struct stack *createStack(int x)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->capacity = x;
    s->arr = (char *)malloc(sizeof(int) * s->capacity);
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

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Empty!!\n");
        return '@';
    }

    char res = s->arr[s->top];
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

int size(struct stack *s)
{
    return (s->top + 1);
}

void display(struct stack *s)
{
    int x = size(s);
    for (int i = 0; i < x; i++)
    {
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

void checkPalindrom(struct stack *s, char str[])
{
    bool ispalindrome = true ;
    int length = strlen(str);

    int i, mid = length / 2;

    for (i = 0; i < mid; i++)
    {
        push(s , str[i]);
    }

    if (length % 2 != 0)
    {
        i++;
    }

    // While not the end of the string
    while (str[i] != '\0')
    {
        char ele = pop(s);

        // If the characters differ then the
        // given string is not a palindrome
        if (ele != str[i])
            ispalindrome = false;
            break;
        i++;
    }

    if (ispalindrome)
    {
        printf("YES!!\n");
    }
    else
    {
        printf("NO!!\n");
    }
}

int main()
{
    char arr[10];
    printf("Enter the string : \n");
    scanf("%s", &arr);
    int len = strlen(arr);
    struct stack *s = createStack(len);

    checkPalindrom(s, arr);

    return 0;
}