#include<stdio.h>
#include<stdlib.h>
struct myArray
{
    int total_size, used_size ; 
    int *ptr ;
};
void createArray(struct myArray* a , int tSize ,int uSize ){
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int *)malloc(tSize*sizeof(int));
}

void show(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d  ", (a->ptr)[i]);
    }
    
}

void setValue(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the value of %d element : \n",i+1);
        scanf("%d", &((a->ptr)[i]));
    }
    
}
int main(){
    struct myArray marks;
    createArray(&marks , 10 , 3);
    printf("Running set function : \n");
    setValue(&marks);
    printf("Running show function : \n");
    show(&marks);

    return 0;
}