#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          
    struct node *next; 
}*head;

void createList(int n);
void traverseList();


int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list \n");
    traverseList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; 
    head->next = NULL; 


    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;    
    }
}



void traverseList()
{
    struct node *temp;
    
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); 
        temp = temp->next;           
    }
}