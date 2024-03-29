// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    static bool mycomp(Item a, Item b)
    {
        double I1 = (double)a.value / a.weight;
        double I2 = (double)b.value / b.weight;

        return I1 > I2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double res = 0;
        sort(arr, arr + n, mycomp);

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                res += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                res += arr[i].value * ((double)W / arr[i].weight);
                break;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends