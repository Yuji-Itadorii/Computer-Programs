#include<stdio.h>

void stringSort(char arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                char temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
        
    }
    
}

void get_string_row(int row , int coloumn , char arr[row][coloumn]){
    printf("The Row-wise sorted string is : \n");
    for (int i = 0; i < row; i++)
    {
        char str[row];
        for (int j = 0; j < coloumn; j++)
        {
            str[j] = arr[i][j];
        }
        stringSort(str, 3);
        printf("%s\n",str);
        
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