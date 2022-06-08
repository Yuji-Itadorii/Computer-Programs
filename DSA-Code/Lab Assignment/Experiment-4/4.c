#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Employee
{
    int Employee_no;
    int salary;
    char name[30];
};

void display(struct Employee *ptr, int size)
{
    printf("\nDisplaying Information:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%s  %d  %d\n", (ptr + i)->name, (ptr + i)->Employee_no, (ptr + i)->salary);
    }
}

void insert(struct Employee * ptr , int *size){
    int a, b ;
    char c[10];
    printf("Enter the Details of Employee which to be inserted (Name , Employee_no , salary) : -\n");
    scanf("%s %d %d" , &c , &a , &b);
    strcpy((ptr + *size)->name,c);
    (ptr+ *size)->Employee_no = a;
    (ptr+ *size)->salary = b;
    *size = *size +1;
}



int main()
{
    struct Employee *ptr;
    int size;
    printf("Enter the number of records: ");
    scanf("%d", &size);

    ptr = (struct Employee *)malloc(size * sizeof(struct Employee));
    for (int i = 0; i < size; ++i)
    {
        printf("Enter Name , Employee Number and salary:\n");
        scanf("%s %d %d", &(ptr + i)->name, &(ptr + i)->Employee_no, &(ptr + i)->salary);
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