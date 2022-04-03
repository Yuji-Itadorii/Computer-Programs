#include<stdio.h>
#include<math.h>
int main(){
    int a , arr[3];
    printf("Enter the number : \n");
    scanf("%d",&a);
    for (int i = 0; i < 3; i++)
    {
        arr[i]=(a%10);
        a=a-arr[i];
        a=a/10;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d",arr[i]);
    }
    
    
    
    

    return 0;
}