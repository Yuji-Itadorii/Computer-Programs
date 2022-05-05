#include <stdio.h>
int factorial(int n)
{
    int res = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            res = res*i;
        }
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",factorial(n));
    return 0;
}