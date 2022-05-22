#include<stdio.h>
int count ;
struct student
{
   int faculty_name, faculty_ID, subject_codes,class_names;
};

void bubblesort(int size ,struct student arr[size]){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j].faculty_ID>arr[j+1].faculty_ID)
            {
                count++;
                struct student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

void dispaly(int size ,struct student arr[size]){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i].faculty_ID);
    }
    
}

int main(){
    int size;
    scanf("%d",&size);
    struct student arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i].faculty_ID);
    }

    bubblesort(size,arr);

    dispaly(size , arr);

    printf("\n the no of swap is : %d",count);
    
    return 0;
}