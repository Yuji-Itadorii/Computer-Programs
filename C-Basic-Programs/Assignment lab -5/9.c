#include<stdio.h>
int main(){
    int s1 , s2;
    printf("Enter the size of arrayy 1 and array 2 :");
    scanf("%d %d", &s1 ,&s2);
    int arr1[s1] , arr2[s2];
    printf("Enter the element od array 1 :");
    for (int i = 0; i < s1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the element od array 2 :");
    for (int i = 0; i < s2; i++)
    {
        scanf("%d",&arr2[i]);
    }

    int counter = 1;
    while (counter<s1)
    {
    for (int i = 0; i < s1-counter; i++)
    {
        if(arr1[i]>arr1[i+1]){
                int temp = arr1[i];
                arr1[i]=arr1[i+1];
                arr1[i+1]=temp;
            }
    }
    counter++;
    } 
    counter = 1;
    while (counter<s2)
    {
    for (int i = 0; i < s2-counter; i++)
    {
        if(arr2[i]>arr2[i+1]){
                int temp = arr2[i];
                arr2[i]=arr2[i+1];
                arr2[i+1]=temp;
            }
    }
    counter++;
    } 
    int check = 0;
    for (int  i = 0; i < s1; i++)
    {
        if(arr1[i] == arr2[i]){
            check++;
        }
    }

    (check==(s1) && s1==s2)? printf("Yes the arrarys are equal") : printf("No the arrarys are not equal") ;
    
    return 0;
}