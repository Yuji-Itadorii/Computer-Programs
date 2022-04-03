#include<stdio.h>
float average(int arr[] , int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum/size;
}
int maximum(int arr[] , int size ){
    int elem = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(elem<arr[i]){
            elem = arr[i];
        }
    }
    return elem;
    
}
int Sec_maximum(int ar[] , int size ){
    int a = maximum(ar , size);
    for (int i = 0; i < size; i++)
    {
        if (a==ar[i])
        {
            ar[i] = 0;
        }
        
    }
    
    int elem = ar[0];
    for (int i = 0; i < size; i++)
    {
        if(elem<ar[i]){
            elem = ar[i];
        }
    }
    return elem;
    
}
int minimum(int arr[] , int size ){
    int elem = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(elem>arr[i]){
            elem = arr[i];
        }
    }
    return elem;
    
}
int main(){
    int arr[5] = { 5,3,7,1,4};
    printf("Average is %0.2f \n", average(arr , 5));
    printf("Max is %d \n", maximum(arr , 5));
    printf("Min is %d \n", minimum(arr , 5));
    printf("Second Max is %d \n", Sec_maximum(arr , 5));
    return 0;
}