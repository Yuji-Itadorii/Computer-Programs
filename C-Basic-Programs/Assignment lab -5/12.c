#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int temp1= arr[0] ;
   for (int i = 0; i < n; i++)
   {
       if (temp1<arr[i])
       {
           temp1 = arr[i];
       }
       else{
           continue;
       }   
   }

   printf("The largest element is : %d",temp1);
       
    return 0;
}