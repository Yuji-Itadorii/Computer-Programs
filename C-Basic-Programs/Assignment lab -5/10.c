#include<stdio.h>
int main(){
    int n ;
    printf("enter the no. of student : ");
    scanf("%d",&n);
    int  phy[n] , math[n] , chem[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks of student %d -- \n", i+1);
        printf("Physics: ");
        scanf("%d",&phy[i]);
        printf("Maths: ");
        scanf("%d",&math[i]);
        printf("Chemistry: ");
        scanf("%d",&chem[i]);
    }

   //physics
   int temp1= phy[0] , counter1 = 0;
   for (int i = 0; i < n; i++)
   {
       if (temp1<phy[i])
       {
           temp1 = phy[i];
           counter1 = i;
       }
       else{
           continue;
       }   
   }
   //maths
   int temp2= math[0] , counter2 = 0;
   for (int i = 0; i < n; i++)
   {
       if (temp2<math[i])
       {
           temp2 = math[i];
           counter2 = i;
       }
       else{
           continue;
       }   
   }
   //chemistry
   int temp3= chem[0] , counter3 = 0;
   for (int i = 0; i < n; i++)
   {
       if (temp3<chem[i])
       {
           temp3 = chem[i];
           counter3 = i;
       }
       else{
           continue;
       }   
   }
   printf("The total marks scored by the student having highest marks in Physics : %d\n", phy[counter1]+math[counter1]+chem[counter1]);
   printf("The total marks scored by the student having highest marks in Maths : %d\n", phy[counter2]+math[counter2]+chem[counter2]);
   printf("The total marks scored by the student having highest marks in Chemistry : %d\n", phy[counter3]+math[counter3]+chem[counter3]);
   
   if (counter1 == counter2 || counter1 == counter3 || counter2 == counter3 )
   {
       printf("The student %d has scored higest in more than one subject!!", counter1+1);
   }
   
    
    return 0;
}