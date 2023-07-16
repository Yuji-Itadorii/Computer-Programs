// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution
{
public:
    class Node
    {
    public:
        int data;
        int row;
        int nextCol;
        Node(int data, int row, int nextCol)
        {
            this->data = data;
            this->row = row;
            this->nextCol = nextCol;
        }
    };

    struct compare
    {
        bool operator()(Node a, Node b)
        {
            return a.data > b.data;
        }
    };

    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        // code here
        priority_queue<Node, vector<Node>, compare> pq;

        int maxi = 0; // Maximum element found so far
        int range = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            pq.push(Node(arr[i][0], i, 0));
            maxi = max(maxi, arr[i][0]);
        }

        int start = -1; // Start of the smallest range
        int end = -1;   // End of the smallest range

        while (!pq.empty())
        {
            Node n1 = pq.top(); // Get the minimum element from
                                // the priority queue
            pq.pop();
            int min = n1.data; // Current minimum element

            // is smaller range found
            if (range > maxi - min)
            {
                range = maxi - min; // Update the smallest range
                start = min;        // Update the start of the smallest
                                    // range
                end = maxi;         // Update the end of the smallest
                                    // range
            }

            int nextRow = n1.row;        // Next row index
            int nextColumn = n1.nextCol; // Next column index
            if (n1.nextCol + 1 < n)
            {
                pq.push(Node(
                    arr[nextRow][nextColumn + 1], nextRow,
                    nextColumn + 1)); // Push the next element
                                      // from the same list into
                                      // the priority queue
                maxi = max(
                    maxi,
                    arr[nextRow]
                       [nextColumn + 1]); // Update the maximum element
            }
            else
                break; // Break if reached the end of any list
        }

        return {start, end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends