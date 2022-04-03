#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter three distinct number : ");
    scanf("%d %d %d",&a,&b,&c);
    (a<b)?(a<c)?printf("The smallest number is : %d" , a):printf("The smallest number is : %d" , c):(b<c)?printf("The smallest number is : %d" , b):printf("The smallest number is : %d" , c);
    return 0;
}