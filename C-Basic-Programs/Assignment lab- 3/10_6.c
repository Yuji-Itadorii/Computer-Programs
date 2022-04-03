#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of n  : ");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <n-i; j++)
        { 
            printf("  ");
        }
        int a=1 , b = 0;
        for (int j = 0; j < i ; j++)
        {   
            if (a>9)
            {  
                printf("%d ",b);
                b++;
            }
            else{
            printf("%d ",a);
            a++;
            }
        }
            int c = i - 1 , d=(i%10)-1;;
        for ( int j = 1; j <= i-1; j++)
        {   
            if (c>9)
            {   
                printf("%d ",d);
                d--;
            }
            else{
            printf("%d ", c);
            }
            c--;
        }
        

        
        printf("\n");
    }
    
       
    return 0;
}