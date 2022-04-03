#include<stdio.h>
int main(){
    int d , m , year ;
    printf("Enter the date in the format (d,m,y) :");
    scanf("(%d,%d,%d)",&d,&m,&year);
    int leap ;
   if (year % 400 == 0) {
      leap = 1;
   }
   else if (year % 100 == 0) {
      leap = 0;
   }
   else if (year % 4 == 0) {
      leap = 1;
   }
   else {
      leap = 0;
   }

    switch (m)
    {
    case 1 && (1||0): printf("The number of reamining days : %d", 31 - d);
        break;
    case 2 : (leap==1)?printf("The number of reamining days : %d", 29 - d):printf("The number of reamining days : %d", 28 - d);
        break;
    case 3 : printf("The number of reamining days : %d", 31 - d);
        break;
    case 4 : printf("The number of reamining days : %d", 30 - d);
        break;
    case 5 : printf("The number of reamining days : %d", 31 - d);
        break;
    case 6 : printf("The number of reamining days : %d", 30 - d);
        break;
    case 7 : printf("The number of reamining days : %d", 31 - d);
        break;
    case 8 : printf("The number of reamining days : %d", 31 - d);
        break;
    case 9 : printf("The number of reamining days : %d", 30 - d);
        break;
    case 10 : printf("The number of reamining days : %d", 31 - d);
        break;
    case 11 : printf("The number of reamining days : %d", 30 - d);
        break;
    case 12 : printf("The number of reamining days : %d", 31 - d);
        break;
    
    default:printf("Please enter the dates in correct format !");
        break;
    }    

    return 0;
}