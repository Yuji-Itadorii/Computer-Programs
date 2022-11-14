#include<stdio.h>
#include<stdlib.h>
struct node
{
    int power;
    int coeff;
    struct node * next;
};

struct node* addnode(struct node* start, int coeff, int power)
{
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
 
    if (start == NULL)
        return newnode;
 
    struct node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
 
    return start;
}

struct node * createList( int size){
    int e;
    int c;
    struct node * head = NULL;
    printf("Enter the coefficient and exponent of linkList members :-\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d",&c , &e);
        head = addnode(head , c , e) ;
    }  
    return head;
}

void printList(struct node * head){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    struct node * temp = head;
    while (temp!=NULL)
    {
        printf("%dx^%d ",temp->coeff,temp->power);
        temp = temp->next;
    } 
}

void removeSameTerm(struct node * head3){
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head3;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) {
 
            if (ptr1->power == ptr2->next->power) {
 
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

struct node * multiplyPol(struct node * head1 , struct node * head2 , struct node * head3){
    struct node * p1 = head1;
    struct node * p2 = head2;
    while (p1!=NULL)
    {
        while (p2!=NULL)
        {
            int c = p1->coeff*p2->coeff;
            int e = p1->power + p2->power;
            head3 = addnode(head3,c,e);
            p2 = p2->next;
        }
        p2 = head2;
        p1 = p1->next;
    }
    removeSameTerm(head3);
    return head3;
}

int main(){

    struct node * head1 = NULL;
    struct node * head2 = NULL;
    struct node * head3 = NULL;
    printf("Enter the size of list :\n");
    int size;
    scanf("%d",&size);
    head1 = createList(size);

    printf("Enter the size of list :\n");
    scanf("%d",&size);
    head2 = createList(size);

    printList(head1);
    printf("\n");
    printList(head2);

    head3 = multiplyPol(head1,head2 , head3);
    printf("\nThe Multiplication of two given polynomial is :-\n");
    printList(head3);
    return 0;
}