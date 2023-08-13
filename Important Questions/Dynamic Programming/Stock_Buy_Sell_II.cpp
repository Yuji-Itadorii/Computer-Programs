// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    // code here
    vector<int> buy, sell;

    int i = 0, ct = 0;
    while (i < n - 1)
    {
        while ((i < n - 1) && (price[i] >= price[i + 1]))
            i++;

        if (i == n - 1)
            break;

        buy.push_back(i++);

        while ((i < n) && (price[i] >= price[i - 1]))
            i++;

        sell.push_back(i - 1);
        ct++;
    }

    if (ct == 0)
        cout << "No Profit" << endl;

    else
    {
        for (int j = 0; j < ct; j++)
        {
            cout << "(" << buy[j] << " " << sell[j] << ") ";
        }
        cout << endl;
    }
}

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> prices(n);
        Array::input(prices, n);

        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);

        cout << res << endl;
    }
}

// } Driver Code Ends