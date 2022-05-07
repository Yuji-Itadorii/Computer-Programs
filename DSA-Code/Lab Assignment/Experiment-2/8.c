#include<stdio.h>
int main(){
    int row , coloumn ; 
    scanf("%d %d",&row , &coloumn);
    int arr[row][coloumn];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            if (j==0)
            {
               int temp =  arr[i][j];
               arr[i][j] = arr[i][j+2];
               arr[i][j+2] = temp;
            }
            
        }
        
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
               printf("%d ",arr[i][j]);
        }
        printf("\n");
    }



    
    return 0;
}