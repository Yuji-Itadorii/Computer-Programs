#include<stdio.h>
#include<stdbool.h>
bool isprime(int n){
    if(n==1)
    return false;
    if(n==2)
    return true;
    for (int i = 2; i*i <=n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
        
    }
    return true;
    
}
int main(){
    int n;
    scanf("%d",&n);
    if (isprime(n))
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    return 0;
}