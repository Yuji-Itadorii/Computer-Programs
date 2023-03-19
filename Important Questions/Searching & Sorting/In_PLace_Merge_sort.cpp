// https://practice.geeksforgeeks.org/problems/merge-sort/1

//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int a[], int l, int m, int r)
    {
        int mx = max(a[m], a[r]) + 1;
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r && k <= r)
        {

            // recover back original element to compare
            int e1 = a[i] % mx;
            int e2 = a[j] % mx;
            if (e1 <= e2)
            {
                a[k] += (e1 * mx);
                i++;
                k++;
            }
            else
            {
                a[k] += (e2 * mx);
                j++;
                k++;
            }
        }

        while (i <= m)
        {
            int el = a[i] % mx;
            a[k] += (el * mx);
            i++;
            k++;
        }

        while (j <= r)
        {
            int el = a[j] % mx;
            a[k] += (el * mx);
            j++;
            k++;
        }

        for (int i = l; i <= r; i++)
            a[i] /= mx;
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends