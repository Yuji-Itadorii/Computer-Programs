#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node * createList( int size){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter the data of linkList :-\n");
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;
    struct node * temp = head;
    for (int i = 0; i < size-1; i++)
    {
        struct node * newNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }
    
    return head ;
    
}

void printList(struct node * head){
    struct node * temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

struct node * pairWiseReverseList(struct node * head){
   struct node * curr = head ;
   while (curr!=NULL &&  curr->next!=NULL)
   {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        
        curr = curr->next->next;
   }
   return head;
}

int main(){

    struct node * head ;
    int size;
    printf("Enter the size of linkList-1\n");
    scanf("%d",&size);
    head = createList(size);

    head = pairWiseReverseList(head);

    printList(head);

    
    return 0;
}