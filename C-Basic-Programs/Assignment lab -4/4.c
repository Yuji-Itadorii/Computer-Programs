#include<stdio.h>
void main()
{
    int date,year,days,year1,month,leap;
    printf("enter date in dd/mm/yyyy format ");
    scanf("%d%d%d",&date,&month,&year);
    year1=year-1;
    days=year1*365+(year1/4+year1/400-year1/100);
    if((year%4==0&&year%100!=0)||(year%400==0))
    leap=1;
    else
    leap=0;
    switch(month-1)
    {
        case 0:
        days=days+date;
        break;
        case 1:
        days=days+31+date;
        break;
        case 2:
        days=days+leap+59+date;
        break;
        case 3:
        days=days+leap+90+date;
        break;
        case 4:
        days=days+leap+120+date;
        break;
         case 5:
        days=days+leap+151+date;
        break;
         case 6:
        days=days+leap+181+date;
        break;
         case 7:
        days=days+leap+212+date;
        break;
         case 8:
        days=days+leap+243+date;
        break;
         case 9:
        days=days+leap+273+date;
        break;
         case 10:
        days=days+leap+304+date;
        break;
         case 11:
        days=days+leap+334+date;
        break;
        default:
        break;

    }
    int rem=days%7;
    switch(rem)
    {
        case 0:
        printf("sunday");
        break;
        case 1:
        printf("monday");
        break;
         case 2:
        printf("tuesday");
        break;
        case 3:
        printf("wednesday");
        break;
         case 4:
        printf("thursday");
        break;
         case 5:
        printf("friday");
        break;
         case 6:
        printf("saturday");
        break;
        default:
        break;
    }
}