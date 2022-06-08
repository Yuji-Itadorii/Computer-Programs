// structures (contains faculty_faculty_name, faculty_ID, subject_codes, class_faculty_names).

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct faculty
{
    int faculty_id;
    int salary;
    int Subject_code;
    char faculty_name[30];
    char class_faculty_name[30];
};

void display(struct faculty *ptr, int size)
{
    printf("\nDisplaying Information:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%s %s %d  %d %d\n", (ptr + i)->faculty_name,(ptr + i)->class_faculty_name, (ptr + i)->faculty_id, (ptr + i)->salary,(ptr + i)->Subject_code);
    }
}

void insert(struct faculty * ptr , int *size){
    int a, b , e;
    char c[10];
    char d[10];
    printf("Enter the Details of faculty which to be inserted (faculty_name , class_faculty_name, faculty_id , salary , subject_code) : -\n");
    scanf("%s %s %d %d %d" , &c , &d , &a , &b , &e);
    strcpy((ptr + *size)->faculty_name,c);
    strcpy((ptr + *size)->class_faculty_name,d);
    (ptr+ *size)->faculty_id = a;
    (ptr+ *size)->salary = b;
    (ptr+ *size)->Subject_code = e;

    *size = *size +1;
}



int main()
{
    struct faculty *ptr;
    int size;
    printf("Enter the number of records: ");
    scanf("%d", &size);

    ptr = (struct faculty *)malloc(size * sizeof(struct faculty));
    for (int i = 0; i < size; ++i)
    {
        printf("Enter faculty_name , class_faculty_name, faculty_id , salary , subject_code:\n");
        scanf("%s %s %d %d %d", &(ptr + i)->faculty_name,&(ptr + i)->class_faculty_name, &(ptr + i)->faculty_id, &(ptr + i)->salary, &(ptr + i)->Subject_code);
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