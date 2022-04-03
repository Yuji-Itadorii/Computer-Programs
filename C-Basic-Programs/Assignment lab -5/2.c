#include<stdio.h>
int main(){
    int size , temp;
    scanf("%d",&size);
    temp = size;
    int arr[size];
    for(int i = 0 ; i< size ; i++){
        scanf("%d",&arr[i]);
    }
    int elm =arr[0];
    while(size--){
        if (elm<arr[size])
        {
            elm = arr[size];
        }
        else{
            continue;
        }
    }
    printf("largest element is : %d\n", elm);
    elm = arr[0];
    while(temp--){
        if (elm>arr[temp])
        {
            elm = arr[temp];
        }
        else{
            continue;
        }
    }
    printf("Smallest element is : %d", elm);
    return 0;
}