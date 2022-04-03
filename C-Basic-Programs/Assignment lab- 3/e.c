#include<stdio.h>
int main(){
    int a , digit , arr[4];
    printf("enter the number : ");
    scanf("%d", &a);
    printf("enter the number : ");
    scanf("%d", &digit);
    for (int i = 0; i < 4; i++)
    {
        arr[i]=(a%10);
        a=a-arr[i];
        a=a/10;
    }
    // printf("%d", arr[2]);
    if (arr[3]==digit)
    {
        printf("Yes");
    }
    else{
        printf("No");
    }
    
 
    return 0;
}