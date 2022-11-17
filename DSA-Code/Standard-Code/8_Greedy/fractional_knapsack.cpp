#include <bits/stdc++.h>
using namespace std;

bool mycomp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return r1 > r2;
}

double FknapSack(pair<int, int> p[], int n, int w)
{
    double res = 0;
    sort(p, p + n, mycomp);

    for (int i = 0; i < n; i++)
    {
        if (p[i].second <= w)
        {
            res += p[i].first;
            w -= p[i].second;
        }
        else
        {
            res +=  p[i].first * ((double)w / p[i].second);
            break;
        }
    }
    return res;
}

int main()
{
    int n = 3;
    pair<int, int> p[5] = {{25, 18}, {24, 15}, {15, 10}};
    int w = 20;

    cout << FknapSack(p, n, w);

    return 0;
}