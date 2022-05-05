#include<stdio.h>
#include<stdbool.h>
int LargestNumber(int arr[] , int n){
   int ele = arr[0];
   for (int i = 0; i < n; i++)
   {
       if (ele <=arr[i])
       {
           ele = arr[i];
       }  
   }
   return ele;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",LargestNumber(arr , n));
    return 0;
}