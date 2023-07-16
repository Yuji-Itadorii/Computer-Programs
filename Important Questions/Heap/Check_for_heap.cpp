// https://practice.geeksforgeeks.org/problems/does-array-represent-heap4345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            int left = -1, right = -1;
            if ((2 * i + 1) < n)
            {
                left = 2 * i + 1;
            }

            if ((2 * i + 2) < n)
            {
                right = 2 * i + 2;
            }

            if (left != -1)
            {
                if (arr[i] < arr[left])
                {
                    flag = false;
                }
            }

            if (right != -1)
            {
                if (arr[i] < arr[right])
                {
                    flag = false;
                }
            }

            if (flag == false)
            {
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[4 * n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.isMaxHeap(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends