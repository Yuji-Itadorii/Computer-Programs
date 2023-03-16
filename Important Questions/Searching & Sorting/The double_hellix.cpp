// https://www.spoj.com/problems/ANARC05B/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int l1, int l2)
    {

        // Your code here
        int sum = 0;
        int i = 0, j = 0;
        int sum_a = 0, sum_b = 0;
        while (i < l1 && j < l2)
        {

            if (A[i] < B[j])
            {
                sum_a += A[i];
                i++;
            }
            else if (B[j] < A[i])
            {
                sum_b += B[j];
                j++;
            }
            else
            {
                sum += max(sum_a, sum_b) + A[i];
                sum_a = 0, sum_b = 0;
                i++;
                j++;
            }
        }

        while (i < l1)
            sum_a += A[i++];

        while (j < l2)
            sum_b += B[j++];

        sum += max(sum_a, sum_b);

        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        Solution obj;
        int result = obj.max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends