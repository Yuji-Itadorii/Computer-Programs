// 13) Given numbers of days, Compute numbers of years, months & remaining days. Can
// you handle leap years as well?
#include <stdio.h>
 
void main()
{
    int ndays, year, week, days;
 
    printf("Enter the number of days\n");
    scanf("%d", &ndays);
    year = ndays / 365;
    week =(ndays % 365) / 7;
    days =(ndays % 365) % 7;
    printf ("%d is equivalent to %d years, %d weeks and %d days",
            ndays, year, week, days);
}