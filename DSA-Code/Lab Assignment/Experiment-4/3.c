#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
    int rollno;
    int marks;
    char name[30];
};

void display(struct student *ptr, int size)
{
    printf("\nDisplaying Information:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%s  %d  %d\n", (ptr + i)->name, (ptr + i)->rollno, (ptr + i)->marks);
    }
}

void insert(struct student * ptr , int *size){
    int a, b ;
    char c[10];
    printf("Enter the Details of student which to be inserted (Name , rollno , marks) : -\n");
    scanf("%s %d %d" , &c , &a , &b);
    strcpy((ptr + *size)->name,c);
    (ptr+ *size)->rollno = a;
    (ptr+ *size)->marks = b;
    *size = *size +1;
}



int main()
{
    struct student *ptr;
    int size;
    printf("Enter the number of records: ");
    scanf("%d", &size);

    ptr = (struct student *)malloc(size * sizeof(struct student));
    for (int i = 0; i < size; ++i)
    {
        printf("Enter Name , Roll number and Marks:\n");
        scanf("%s %d %d", &(ptr + i)->name, &(ptr + i)->rollno, &(ptr + i)->marks);
    }

    while (1)
    {

        printf ("\n1. Insertion\n2. Display\n3. exit\n");

        printf("Enter your choices : - \n");
        int choice ; 
        scanf("%d", &choice);
        if (choice==1)
        {
            insert(ptr , &size);
        }
        else if (choice==2)
        {
            display(ptr , size);
        }
        else{
            free(ptr);
            return 0 ;
        }
        
        
    }

    return 0;
}