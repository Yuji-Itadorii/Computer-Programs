#include<stdio.h>

void stringSort(char arr[] , int n){
     int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j-1] > arr[j]){
                char temp;
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    
}

void get_string_row(int row , int coloumn , char arr[row][coloumn]){
    printf("The Row-wise sorted string is : \n");
    for (int i = 0; i < row; i++)
    {
        char str1[row];
        for (int j = 0; j < coloumn; j++)
        {
            str1[j] = arr[i][j];
        }
        stringSort(str1, 3);
        printf("%s\n",str1);
    }
    
}
void get_string_coloumn(int row , int coloumn , char arr[row][coloumn]){
    printf("The coloumn-wise sorted string is : \n");
    for (int i = 0; i < row; i++)
    {
        char str[coloumn];
        for (int j = 0; j < coloumn; j++)
        {
            str[j] = arr[j][i];
        }
        stringSort(str, 3);
        printf("%s\n",str);
        
    }
    
}
int main(){
        int row , coloumn;
        scanf("%d%d",&row , &coloumn);
        char arr[row][coloumn];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coloumn; j++)
            {
                scanf("%s",&arr[i][j]);
            }
            
        }

    get_string_row(row ,coloumn , arr);
    get_string_coloumn(row ,coloumn , arr);

    return 0;
}