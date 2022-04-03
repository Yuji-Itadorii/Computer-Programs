#include<stdio.h>
int main(){
    int a, b;
    printf("Enter thr value of two number : ");
    scanf("%d %d",&a,&b);
    //Arithmetic operator 
    printf("The sum of two number  is : %d\n",a+b);
    printf("The substraction of two number  is : %d\n", a-b);
    printf("The multiplication of two number  is : %d\n",a*b);
    printf("The division of two number  is : %0.2f\n",a/b);
    printf("The reminder when a is divided by b is : %d\n",a%b);

    //Bitwise operator

    printf("The AND of  a and b is : %d\n",a&b);
    printf("The OR of  a and b is : %d\n",a|b);
    printf("The XOR of  a and b is : %d\n",a^b);
    printf("The NOT of  a  is : %d\n",(~a));

    // Shift Operator
    
    printf("The Left shift  of  a  is : %d\n", a<<1);
    printf("The Right shift  of  a  is : %d\n",a>>1);

    //Increment and decrement operator

    printf("The pre increment  of  a  is : %d\n",++a);
    printf("The post increment  of  a  is : %d\n",a++);
    printf("The post decrement  of  a  is : %d\n",--a);
    printf("The post decrement  of  a  is : %d\n",a--);

    //Relational Operator

    printf("%d == %d is %d \n", a, b, a == b);
    printf("%d > %d is %d \n", a, b, a > b);
    printf("%d < %d is %d \n", a, b, a < b);
    printf("%d != %d is %d \n", a, b, a != b);
    printf("%d >= %d is %d \n", a, b, a >= b);
    printf("%d <= %d is %d \n", a, b, a <= b);

    return 0;
}