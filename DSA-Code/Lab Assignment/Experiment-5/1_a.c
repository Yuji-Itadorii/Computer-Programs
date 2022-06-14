#include <stdio.h>
#include <stdlib.h>
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

struct node *insertPos(struct node *head, int x, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }

    struct node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return head;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

struct node * deletePos( struct node * head , int pos){
    
    if(head==NULL)
     return NULL;
    struct node* temp = head;
    if (pos==1)
    {
        temp= head->next;
        free(head);
        return temp;
    }
    
    for (int i = 1; i <pos-1; i++)
    {
        temp = temp->next;
    }
    
     struct node * curr = temp->next;

     temp->next = temp->next->next;
     free(curr);

     return head; 
    
}

struct node * CompletedeletePos( struct node * head){
    
    if(head==NULL)
     return NULL;
    struct node* temp = head;
    if (head->next==NULL)
    {
        temp= head->next;
        free(head);
        return temp;
    }
    
    while(temp!=NULL){

        struct node * curr = temp->next;
        free(temp);
        temp = curr;

    }
     return temp; 
}

struct node *accessNode(struct node *head, int pos)
{
    struct node *temp = head;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp;
}

struct node *copyList(int size , struct node * head_tocopy)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp_tocopy = head_tocopy;
    printf("Enter the data of linkList :-\n");

    head->data = temp_tocopy->data;
    head->next = NULL;
    struct node *temp = head;
    for (int i = 0; i < size - 1; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = temp_tocopy->data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


int main()
{

    struct node *head1;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d", &size1);
    head1 = createList(size1);

    printList(head1);

    head1 = insertPos(head1,100,size1);

    printList(head1);

    head1 = deletePos(head1,size1);

    printList(head1);

    head1 = CompletedeletePos(head1);

    printList(head1);

    return 0;
}