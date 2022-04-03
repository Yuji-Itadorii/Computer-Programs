#include<stdio.h>
#include<math.h>
int main(){
    int a , copy_a, arr[3] , b;
    printf("Enter the number : \n");
    scanf("%d",&a);
    copy_a = a;
    for (int i = 0; i < 3; i++)
    {
        arr[i]=(a%10);
        a=a-arr[i];
        a=a/10;
    }

    b=arr[0]*100+arr[1]*10+arr[2];

    if (copy_a==b)
    {
    printf("yes , the reverse of the given number is equal to number!"); 
    }
    else{
        printf("No, the reverse of the given number is equal to number!");
    }
    

    
    

    return 0;
}