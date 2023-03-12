// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    sort(arr, arr + n);

    int pre_sum[n + 1];
    pre_sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre_sum[i] = arr[i - 1] + pre_sum[i - 1];
    }

    while (q--)
    {
        int x;
        cin >> x;

        int idx = upper_bound(arr, arr + n, x) - arr;
        cout << idx << " " << pre_sum[idx] << endl;
    }

    return 0;
}
