#include<stdio.h>
#include<math.h>
int main(){
    int a , copy_a, b = 0, i =0;
    printf("Enter the number : \n");
    scanf("%d",&a);
    copy_a = a;
    while(1)
    {   
        if(a==0){
            break;
        }
        int digit = 0;
        digit=(a%10);
        a=a-digit;
        a=a/10;
        b = b*10+digit;
        i++;
        
    }
    if (copy_a==b)
    {
    printf("yes , It is palindrome number!"); 
    }
    else{
        printf("No, It is not palindrome number!");
    }
    return 0;
}