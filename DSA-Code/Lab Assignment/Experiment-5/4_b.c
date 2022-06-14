#include <stdio.h>
#include <stdlib.h>
struct node
{
    int power;
    int coeff;
    struct node *next;
};

struct node *addnode(struct node *start, int coeff, int power)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;

    if (start == NULL)
        return newnode;

    struct node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}

struct node *createList(int size)
{
    int e;
    int c;
    struct node *head = NULL;
    printf("Enter the coefficient and exponent of linkList members :-\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d", &c, &e);
        head = addnode(head, c, e);
    }
    return head;
}

void printList(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->power);
        temp = temp->next;
    }
}

void comparePolynomial(struct node *head1, int size1, struct node *head2, int size2)
{
    struct node *p1 = head1;
    struct node *p2 = head2;
    if (size1 != size2)
    {
        printf("NOT EQUAL!!\n");
        return;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->coeff != p2->coeff || p1->power != p1->power)
        {
            printf("NOT EQUAL!!\n");
            return;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    printf("EQUAL!!\n");
}

int main()
{

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("Enter the size of list :\n");
    int size1;
    scanf("%d", &size1);
    head1 = createList(size1);

    int size2;
    printf("Enter the size of list :\n");
    scanf("%d", &size2);
    head2 = createList(size2);

    printList(head1);
    printf("\n");
    printList(head2);

    comparePolynomial(head1, size1, head2, size2);
    return 0;
}