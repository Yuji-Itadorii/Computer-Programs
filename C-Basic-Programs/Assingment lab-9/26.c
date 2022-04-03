#include<stdio.h>
int main(){
    int a, b ,result=1;
    printf("Enter the value of base number : ");
    scanf("%d",&a);
    printf("Enter the value of power number : ");
    scanf("%d",&b);
    for (int i = 1; i <=b; i++)
    {
        result = result*a; 
    }

    printf("%d",result);
    
    return 0;
}