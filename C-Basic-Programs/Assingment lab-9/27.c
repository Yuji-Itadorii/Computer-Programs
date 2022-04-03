#include<stdio.h>
int main(){
    int a ,result=1;
    printf("Enter the number : ") ;
    scanf("%d",&a);
    if(a==0){
        printf("The factorial of %d is : %d",a,1);
        }
    else{
    for (int i = 1; i<=a; i++)
    {
        result=result*i;   
    }
    printf("The factorial of %d is : %d",a,result);
    }
    
    
    return 0;
}