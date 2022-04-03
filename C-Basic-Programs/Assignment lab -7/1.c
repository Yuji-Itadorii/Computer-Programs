#include<stdio.h>
int fac( int n){
    int b = 1;
    for (int i = 1; i <=n; i++)
    {
        b = b*i;
    }
    return b;
}
int main(){
    int n = 4, r = 2;
    float result = fac(n)/(fac(n-r)*fac(r));
    printf("%.2f",result);   
    return 0;
}