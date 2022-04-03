// 16) **Find max out of 4 distinct numbers without using && etc
#include<stdio.h>  
int main() {
    printf("Enter the four numbers: \n");
    int a, b, c, d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("the Maximun number is : \n");

     if (a > b) {  
        if (a > c) {  
            if (a > d) {  
                printf("%d" ,a);  
            }  
            else if(d>a){  
                printf("%d" ,d);  
            }  
        }
        else{
             if (b > c) {  
        if (b > d) {  
            printf("%d" ,b);  
        }  
        else {  
            printf("%d" ,d);  
        }  
    }  
    else if (c > d) {  
        printf("%d" ,c);  
    }  
    else {  
        printf("%d" ,d);  
    }
            
        }  
    }  
    else if (b > c) {  
        if (b > d) {  
            printf("%d" ,b);  
        }  
        else {  
            printf("%d" ,d);  
        }  
    }  
    else if (c > d) {  
        printf("%d" ,c);  
    }  
    else {  
        printf("%d" ,d);  
    }  
    
    return 0;
}
