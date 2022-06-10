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

struct node * mergeList(struct node * head1 , int size1 ,struct node * head2 , int size2 ){
   struct node * p1 = head1 ;
   struct node * p2 = head2 ;
   struct node * dummy = (struct node *)malloc(sizeof(struct node)) ;
   struct node * p3 = dummy ;

   while (p1!=NULL && p2!=NULL)
   {
       if (p1->data<=p2->data)
       {
           p3->next = p1;
           p1 = p1->next;
       }
       else{
           p3->next = p2;
           p2 = p2->next;
       }
       p3 = p3->next;
   }

   while (p1!=NULL)
   {
       p3->next = p1;
       p1 = p1->next;
       p3 = p3->next;
   }
   while (p2!=NULL)
   {
       p3->next = p2;
       p2 = p2->next;
       p3 = p3->next;
   }
   
    return dummy->next;
}

int main(){

    struct node * head1 , *head2 , *head3;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d",&size1);
    head1 = createList(size1);

    int size2;
    printf("Enter the size of linkList-2\n");
    scanf("%d",&size2);
    head2 = createList(size2);

    printList(head1);
    printf("\n");
    printList(head2);

    head3 = mergeList(head1 , size1 , head2 , size2);

    printf("\nThe sorted list is :- \n");
    printList(head3);

    

    
    return 0;
}