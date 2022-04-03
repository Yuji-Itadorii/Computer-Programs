#include<stdio.h>
float average(float arr[] , int size){
    float sum=0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum/size;
}

int aboveAverage(float arr[] , int size){
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (average(arr , size)<arr[i])
        {
            count++;
        }
        
    }
    return count;
    
}

int fun(float arr[] , int size){
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if ((arr[i]+arr[j])<average(arr , size) && j==i+1)
            {
                count++;
            }
            
        }
    }
    return count;
}

int main(){
    float arr[5] = { 5.0,3.0,7.0,1.0,2.0};
    printf("Average is %0.2f \n", average(arr , 5));
    printf("Above Average numbers are %d \n", aboveAverage(arr , 5));
    printf(" All pairs of two consecutive values such that sum of the pair is less than the average are %d \n", fun(arr , 5));    
    return 0;
}