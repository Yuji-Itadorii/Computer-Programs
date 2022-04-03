#include<stdio.h>
int main(){
    int a, b,c , d , n;
    printf("Enter the four starting number of series :");
    scanf("%d %d %d %d",&a,&b,&c , &d);
    printf("Enter the value of n :");
    scanf("%d",&n);
    if (a<0||b<0)
    {
        //for positive series 
        int n_half;
        if(n%2==0){n_half=n/2;}
        else{n_half=n/2 + 1;}
        
        int d_positive = (c)-(a) , sum_postive=0 , i = 1;
        do
        {
            sum_postive = sum_postive + ( a+(i-1)*(d_positive));
            i++;
        }while (i<=n_half);
        int d_negative =  (d)-(b) , sum_negative = 0 , j=1;
        n_half = n/2;
        do
        {
            sum_negative = sum_negative + ( b+(j-1)*(d_negative));
            j++;
        }while (j<=n_half);

        // printf("The sum_positive of series is  : %d\n", sum_postive);
        // printf("The sum_negative of series is  : %d\n", sum_negative);
        printf("The sum of series is  : %d\n", sum_postive+sum_negative);

        
    }
    else
    {
        int common_diff , sum =0  , i = 1;
        common_diff= (b) - (a);
        do
        {
            sum = sum + ( a+(i-1)*(common_diff));
            i++;
        }while (i<=n);
        printf("The sum of series is  : %d", sum);
    }
    return 0;
}