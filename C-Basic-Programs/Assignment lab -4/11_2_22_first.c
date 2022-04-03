// 6) Check whether a number is even/odd 
#include<stdio.h>
int main(){
    int a ;
    printf("Enter the number: \n");
    scanf("%d" , &a );
    int b = a%2;
    ;
    switch (b)
    {
    case 0: printf("The number is even\n");
        break;
    
    case 1 : printf("The number is odd\n");
        break;
    }
    
    return 0;
}