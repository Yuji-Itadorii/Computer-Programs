// 1) Input 2 distinct numbers . Using if (no else), show which is bigger.
#include<stdio.h>
int main(){
    int a , b;
    printf("Enter the two number: \n");
    scanf("%d %d" , &a , &b);
    if (a>b)
    {
        printf("%d is bigger",a);
    }
    else{
        printf("%d is bigger",b);
    }

     // 2) Input 2 numbers. Using if (not else) 
    //  (i) If first is bigger add both. 
    //  (ii) If 2nd is bigger subtract. 
    printf("Enter the two number: \n");
    scanf("%d %d" , &a , &b);
    if (a>b)
    {
        printf("The sum is %d",a+b);
    }
    else{
        printf("The subustraction is %d",a-b);
    }
    return 0;
}