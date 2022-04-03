#include<stdio.h>
int main(){
    // 2) Input 2 numbers. Using if (not else) 
    //  (i) If first is bigger add both. 
    //  (ii) If 2nd is bigger subtract. 
    int a , b;
    printf("Enter the two number: \n");
    scanf("%d %d" , &a , &b);
    if (a>b)
    {
        printf("The sum is %d",a+b);
    }
    if(b>a){
        printf("The subustraction is %d",a-b);
    }
    return 0;
}