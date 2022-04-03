#include<stdio.h>
int power(int base , int n){
    int b=1;
    for (int i = 1; i <=n; i++)
    {
        b= b*base;
    }
    return b;
    
}
int main(){
    int base = 2 , n = 5;
    printf("%d",power(base , n));

    return 0;
}