#include<stdio.h>
#include<math.h>
int main(){
       int r_d,r_m,r_y , d,m ,y;
       printf("Enter the recent date in the formate dd,mm,yyyy : \n");
       scanf("%d,%d,%d",&r_d,&r_m,&r_y);
       printf("Enter the past date in the formate dd,mm,yyyy : \n");
       scanf("%d,%d,%d",&d,&m,&y);

       int days_diff_year =0 , days_diff_day = 0, days_diff_month = 0;
       days_diff_year = (r_y - y)*365;
        int day_in_month = 0 ;

     if(r_m==m){
          day_in_month = 0;
     }
     else{
       switch (m)
    {
    case  1 : day_in_month = 31;
        break;
    case   3 : day_in_month = 31;
        break;
    case  5 : day_in_month = 31;
        break;
    case   7 : day_in_month = 31;
        break;
    case   8  : day_in_month = 31;
        break;
    case  10 : day_in_month = 31;
        break;
    case  12 : day_in_month = 31;
        break;
    case 2 : day_in_month = 28;
        break;
    case  4: day_in_month = 30;
        break;
    case   6  : day_in_month = 30;
        break;
    case  9: day_in_month = 30;
        break;
    case 11 : day_in_month = 30;
        break;
    }  
     }  
     
    days_diff_day  = (r_d-1) + (day_in_month - d) ; 




    int arr[12] = { 31 , 28 ,31 , 30,31,30,31,31,30,31,30,31} ;

    for ( int i = 1; i < sqrt((r_m - m)*(r_m - m)) ; i++)
    {   
        if(r_m>m){
        days_diff_month = days_diff_month + arr[m+1] ;
        m++ ;
        }
        else if(m>r_m){
        days_diff_month = days_diff_month + arr[r_m+1] ;
        r_m++ ;  
        }
    }


    int total_days;
    total_days = days_diff_day + days_diff_month + days_diff_year;

//     printf("%d %d %d",days_diff_day,days_diff_month,days_diff_year);
    printf("The no. of days in between given dates are : %d",total_days);

return 0 ;
}