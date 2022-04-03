#include<stdio.h>
int main(){
    int r1,c1,r2,c2;
    printf("Enter the row and coloumn of matrix 1 : ");
    scanf("%d %d",&r1 ,&c1);
    printf("Enter the row and coloumn of matrix 2 : ");
    scanf("%d %d",&r2 ,&c2);
    if(r1!=c1 || r2!=c2 || r1!=r2){
        printf("Summation of matrix is not possible ! ");
        return 0 ;
    }
    int arr1[r1][c1] , arr2[r2][c2];
    printf("Enter the elements of square matrix 1 : ");
    for (int  i = 0; i < r1; i++)
    {
        for (int j = 0; j < r1; j++)
        {
            scanf("%d",&arr1[i][j]);
        }
        
    }   
    printf("Enter the elements of square matrix 2 : ");
    for (int  i = 0; i < r2; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
        
    } 
    int sum ;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r1 ; j++)
        {
            sum = 0;
            sum = sum + arr1[i][j] + arr2[i][j];
            printf("%d ",sum);
            
        }
        
    }
    return 0;
}