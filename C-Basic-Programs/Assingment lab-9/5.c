#include<stdio.h>
int main(){
    int a,b,temp;
    printf("Enter two number : \n");
    scanf("%d %d",&a , &b);
    printf("Value of a and b before swaping is : %d %d \n",a,b);
    temp = a;
    a = b;
    b = temp;
    printf("Value of a and b before swaping is : %d %d \n",a,b);
    
    return 0;
}