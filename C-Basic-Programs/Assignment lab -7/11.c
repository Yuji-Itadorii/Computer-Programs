#include <stdio.h>
void display(int r, int c, int arr[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
}

void matriSumm(int r, int c, int arr1[r][c], int arr2[r][c])
{
    int sum;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum = 0;
            sum = sum + arr1[i][j] + arr2[i][j];
            printf("%d ", sum);
        }
    }
}
int main()
{
    int r1, c1, r2, c2;
    printf("Enter the row and coloumn of matrix 1 : ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the row and coloumn of matrix 2 : ");
    scanf("%d %d", &r2, &c2);
    int arr1[r1][c1], arr2[r2][c2];
    printf("Enter the elements of matrix 1 : ");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the elements of matrix 2 : ");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("Your matrix 1 is : \n");
    display(r1, c1, arr1);
    printf("Your matrix 2 is : \n");
    display(r2, c2, arr2);

    printf("The sum of two given matrix is : \n");


    matriSumm(r1 , c1 ,arr1 , arr2);

    return 0;
}