#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList(int size)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter the data of linkList :-\n");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    struct node *temp = head;
    for (int i = 0; i < size - 1; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void maxOcurrence(struct node *head, int size)
{
    struct node *temp = head;
    int i= 1 , freq = 1;
    while (temp!=NULL)
    {
        struct node * curr = temp;
        while (curr!=NULL && curr->data==curr->next->data)
        {
            freq++;
            curr = curr->next;
        }
        printf("%d - %d \n" ,curr->data ,freq);
        temp = temp->next;
        freq = 1;
    }
    if (temp->next== NULL)
    {
        printf("1");
    }
}

int main()
{

    struct node *head1;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d", &size1);
    head1 = createList(size1);

    maxOcurrence(head1,size1);

    return 0;
}