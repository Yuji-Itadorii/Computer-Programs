#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

int traverseList(struct node * head){
    struct node * temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList(struct node * head){
    struct node * temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


void comapaiorList(struct node* head1 , struct node * head2){
    int size1 = traverseList(head1);
    int size2 = traverseList(head2);

    int pos = abs(size1-size2);

    struct node *curr1 = head1;
    for (int i = 0; i < pos; i++)
    {
        curr1 = curr1->next;
    }
    
    struct node *curr2 = head2;

    while (curr1!=NULL && curr2!=NULL)
    {
        if (curr1==curr2)
        {
            printf("\nThe interssection point is :- %d\n",curr1->data);
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    printf("\nNo intersection point found !!");

}


int main(){

    struct node * head1 , *head2 , *second1 , *third1 , *fourth1 , *second2 ;

    head1 = (struct node *)malloc(sizeof(struct node));
    second1 = (struct node *)malloc(sizeof(struct node));
    second2 = (struct node *)malloc(sizeof(struct node));
    third1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    fourth1 = (struct node *)malloc(sizeof(struct node));

    head1->data = 10;
    head1->next = second1;
    second1->data = 20;
    second1->next = third1;
    third1->data = 30;
    third1->next = fourth1;
    fourth1->data = 40;
    fourth1->next = NULL;

    head2->data = 9;
    head2->next = second2;
    second2->data = 18;
    second2->next = third1;

    printList(head1);
    printf("\n");
    printList(head2);

    
    comapaiorList(head1 , head2);
    
    

    
    return 0;
}