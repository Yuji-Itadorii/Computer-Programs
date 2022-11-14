#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          
    struct node *next; 
}*head;

void createList(int arr[] , int size);
void traverseList();


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    createList( arr ,10);

    printf("\nData in the list \n");
    traverseList();

    return 0;
}

void createList(int arr[] , int size)
{
    struct node *newNode, *temp;
    

    head = (struct node *)malloc(sizeof(struct node));

    head->data = arr[0]; 
    head->next = NULL; 


    temp = head;
    for(int i=1; i<size; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = arr[i]; 
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