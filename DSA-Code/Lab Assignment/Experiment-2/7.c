#include<stdio.h>
void median(int arr1[] , int arr2[] , int size1 , int size2){
    int size3 = size1+size2;
    int arr3[size3];
    for (int i = 0; i < size3; i++)
    {
        if (i<size1)
        {
            arr3[i]=arr1[i];
        }
        else{
            arr3[i]=arr2[i-size1];
        }
        
    }

    int median ;
    if (size3%2==0)
    {
        printf("The median of the given numbers are : %d and %d\n",arr3[(size3-1)/2] , arr3[((size3-1)/2)+1]);
    }
    else{
        printf("The median of the given numbers is : %d\n",arr3[(size3-1)/2]);
    }
    
    
    
}
int main(){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9,10 , 11};
    median(arr1 , arr2 , 5 , 6);
    return 0;
}