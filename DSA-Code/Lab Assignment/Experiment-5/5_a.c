#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
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

void sortLinklist( struct node * head , int size){
    struct node * temp  = head;
    for (int i = 0; i < size - 1 && temp!=NULL; i++)
    {
        struct node * curr = temp;
        bool swapped = false;
        for (int j = 0; j < size - i - 1 && curr!=NULL; j++)
        {
            if (curr->data > curr->next->data)
            {
                swapped = true;
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{

    struct node *head1;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d", &size1);
    head1 = createList(size1);

    sortLinklist(head1 , size1);

    printList(head1);

    return 0;
}