#include<stdio.h>
int main(){
    int arr[3] , temp;
    printf("Enter three  number : \n");
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
    for ( int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (arr[j-1]>arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else{
                continue;
            }
            
        }   
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}