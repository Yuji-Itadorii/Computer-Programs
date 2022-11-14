#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node {
	int rollno;
    int marks;
    char  name[20];
	struct Node* next;
};

void printList(struct Node* n)
{
	while (n != NULL) {
		printf("%s %d %d\n",n->name, n->rollno , n->marks);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

     int a , b;
        char s[20];
        printf("Enter the details of student 1 : - Name , roll_number , Marks\n");
        scanf("%s %d %d",&s,&a,&b);


	head->rollno = a; 
    head->marks = b;
    strcpy(head->name,s);
	head->next = second; 

    printf("Enter the details of student 2 : - Name , roll_number , Marks\n");
        scanf("%s %d %d",&s,&a,&b);

	second->rollno = a;
    second->marks = b;
    strcpy(second->name,s);
	second->next = third;

    printf("Enter the details of student 3 : - Name , roll_number , Marks\n");
        scanf("%s %d %d",&s,&a,&b);

	third->rollno = a; 
    third->marks = b;
    strcpy(third->name,s);
	third->next = NULL;

	printList(head);

	return 0;
}
