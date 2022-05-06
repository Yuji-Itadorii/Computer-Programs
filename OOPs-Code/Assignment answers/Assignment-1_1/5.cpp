#include<iostream>
using namespace std;

int main(){
    int row , coloumn;
    cout<<"Enter the no. of rows : ";
    cin>>row;
    cout<<"Enter the no. of coloumns : ";
    cin>>coloumn;

    char arr[row][coloumn];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            arr[i][j]='A';
        }
        
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}