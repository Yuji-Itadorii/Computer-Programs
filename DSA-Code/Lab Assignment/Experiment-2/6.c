#include<stdio.h>
int main(){
    int count = 0;
    int arr[] = {1,2,3,4,6,7,8,9,10};
    for (int i = 0; i < 9; i++)
    {

        count++;
        if (arr[i]==count)
        {
            continue;
        }
        else{
            printf("%d\n",count);
            break;
        }
        
    }
    
    return 0;
}