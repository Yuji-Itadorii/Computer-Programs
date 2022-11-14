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

void compareList(struct node * head1 , int size1 ,struct node * head2 , int size2 ){
    if (size1!=size2)
    {
        printf("Not equal!!\n");
    }
    else{
        struct node * temp1 = head1;
        struct node * temp2 = head2;

        while (temp1!=NULL)
        {
            if (temp1->data!=temp2->data)
            {
                printf("Not Equal!!\n");
                return;
            }
           temp1 = temp1->next; 
           temp2 = temp2->next; 
        }
        printf("Equal !! \n");
    }
    
}

int main(){

    struct node * head1 , *head2 ;
    int size1;
    printf("Enter the size of linkList-1\n");
    scanf("%d",&size1);
    head1 = createList(size1);

    int size2;
    printf("Enter the size of linkList-2\n");
    scanf("%d",&size2);
    head2 = createList(size2);

    compareList(head1 , size1 , head2 , size2);

    printList(head1);
    printf("\n");
    printList(head2);

    
    return 0;
}