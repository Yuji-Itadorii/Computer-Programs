#include<stdio.h>
#include<stdbool.h>
bool fun( int arr[] ,int size ,int* a){ 
    for (int i = 0; i < size; i++)
    {
        if (arr[i]<0)
        {
            *a = i;
            return true;
        }
    }
    printf("Function run");
        return false;  
    
}
int main(){
    int size , i;
    scanf("%d",&size);
    int arr[size];
    for (i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int *p = &i;
    
    if (fun(arr ,size, p)){
        printf("The index of first negative number is : %d \n ", i );
    }
    int sum = 0;
    for (int j = i+1; j < size; j++)
    {
        sum += arr[j];
    }
    printf("The sum of the array element onward negative term is : %d" , sum);
      
    return 0;
}