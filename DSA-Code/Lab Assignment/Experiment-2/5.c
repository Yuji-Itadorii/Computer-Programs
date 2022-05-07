#include <stdio.h>
int nonReapeating(int arr[], int n)
{   
    int res = 0 , j;
    for (int i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (arr[j] == arr[i])
            {
                break;
            }
        }
        if(j==n)
        res++;
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 9, 4, 5,5};
    printf("%d",nonReapeating(arr , 7));

    return 0;
}