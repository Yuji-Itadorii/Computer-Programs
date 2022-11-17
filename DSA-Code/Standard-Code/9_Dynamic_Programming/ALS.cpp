#include <iostream>
using namespace std;

const int num_Station = 6;
const int num_Line = 2;

int ALS(int arr[][num_Station], int cross_Time[][num_Station], int e[num_Line], int x[num_Line])
{
    int T1[num_Station], T2[num_Station];

    T1[0] = e[0] + arr[0][0];
    T2[0] = e[1] + arr[1][0];

    for (int i = 1; i < num_Station; i++)
    {
        T1[i] = min((T1[i - 1] + arr[0][i]),
                    (T2[i - 1] + arr[0][i] + cross_Time[1][i]));
        // cout<<T1[i]<<" ";
        T2[i] = min((T2[i - 1] + arr[1][i]),
                    (T1[i - 1] + arr[1][i] + cross_Time[0][i]));
        // cout<<T2[i]<<endl;
    }

    return min((T1[num_Station - 1] + x[0]), (T2[num_Station - 1] + x[1]));
}

int main()
{

    int arr[num_Line][num_Station] = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}};

    int cross_Time[num_Line][num_Station] = {{0, 2, 3, 1, 3, 4}, {0, 2, 1, 2, 2, 1}};

    int e[num_Line] = {2, 4};

    int x[num_Line] = {3, 2};

    cout << ALS(arr, cross_Time, e, x);

    return 0;
}