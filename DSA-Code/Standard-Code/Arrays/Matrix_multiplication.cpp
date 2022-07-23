#include<iostream>
using namespace std;

int main(){
    int r1 = 3 , c1 =4;
    int r2 = 4 , c2 =3;

    int arr1[r1][c1];
    int arr2[r2][c2];

    cout<<"Enter the elements of Matrix 1 :-\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
           cin>>arr1[i][j];
        }
        
    }

    cout<<"Enter the elements of Matrix 1 :-\n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
           cin>>arr2[i][j];
        }
        
    }

    int arr3[r1][c2];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
           arr3[i][j]=0;
           for (int k = 0; k < c1; k++)
           {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
           }
           
        }
        
    }


    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
           cout<<arr3[i][j]<<" ";
           
        }
        cout<<endl;
    }

    
    return 0;
}