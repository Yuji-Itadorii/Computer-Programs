// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <bits/stdc++.h>
using namespace std;

// User function template in C++

class Solution
{
public:
    bool isFeasible(int arr[], int n, int k, int ans)
    {
        int req = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((sum + arr[i]) > ans)
            {
                req++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }
        return (req <= k);
    }

    int findPages(int arr[], int N, int M)
    {
        if (N < M)
        {
            return -1;
        }
        int sum = 0, mx = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            mx = max(arr[i], mx);
        }

        int low = mx, high = sum;
        int res = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isFeasible(arr, N, M, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}