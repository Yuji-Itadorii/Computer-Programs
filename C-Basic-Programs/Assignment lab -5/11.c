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

    int temp1= arr[0] , counter = 0;
   for (int i = 0; i < n; i++)
   {
       if (temp1<arr[i])
       {
           temp1 = arr[i];
           counter =  i;
       }
       else{
           continue;
       }   
   }

   printf("The largest element is %d at position %d\n",temp1 , counter);
   printf("These are the elment whose index value is less than largest element: \n");
   for (int i = 0; i < counter; i++)
   {
       printf("%d ",arr[i]);
   }
   printf("\n");
   printf("These are the elment whose index value is greater than largest element: \n");
   for (int i = counter+1; i < n; i++)
   {
       printf("%d ",arr[i]);
   }
   

       
    return 0;
}