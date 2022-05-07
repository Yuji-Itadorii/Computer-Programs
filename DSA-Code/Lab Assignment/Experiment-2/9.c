#include<stdio.h>
void get_string_row(int row , int coloumn , char arr[row][coloumn]){
    printf("HELLO");
}
int main(){
        int row , coloumn;
        scanf("%d %d",&row , &coloumn);
        char arr[row][coloumn];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coloumn; j++)
            {
                scanf("%c" , &arr[i][j]);
            }
            
        }
    get_string_row(row ,coloumn , arr);
    return 0;
}