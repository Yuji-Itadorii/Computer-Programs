#include<stdio.h>
#include<stdbool.h>
bool palindrom(int n){
    int copy = n , rev=0;
    while (n>0)
    {
        int digit = 0;
        digit = n%10;
        rev = rev*10 + digit;
        n=n/10;
    }
    if(rev==copy)
    return true;
    else return false;
}
int main(){
    int n;
    scanf("%d",&n);
    if (palindrom(n))
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
    return 0;
}