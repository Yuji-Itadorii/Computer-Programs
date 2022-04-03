#include <stdio.h> 
int main() 
{ 
	float num; 
    printf("enter the float nnumber : ");
	scanf("%f",&num); 
	
	long long a=num*1000000; 
	
	printf("Integer number is : %llu \n",a ); 
	int sum=0; 
    while(a!=0) 
    { 
    	
    	int rem=a%10; 
    	sum=sum+rem; 
    	a=a/10; 
 
    }     
    
    printf("Sum of digits is : %d\n",sum );   
}