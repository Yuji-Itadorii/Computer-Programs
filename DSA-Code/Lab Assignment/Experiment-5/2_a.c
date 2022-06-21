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

struct node * reverseList(struct node * head){
   if(head == NULL || head->next == NULL)
    return head ;

    struct node * rest_head = reverseList(head->next);
    struct node * rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}

int main(){

    struct node * head1;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d",&size1);
    head1 = createList(size1);

   
    printList(head1);

    head1 = reverseList(head1);

    printf("\n");
    printList(head1);

    
    return 0;
}