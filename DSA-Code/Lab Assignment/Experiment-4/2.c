#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int **ptr1 = (int **)malloc(r * sizeof(int));
    int **ptr2 = (int **)malloc(r * sizeof(int));
    int **ptr3 = (int **)malloc(r * sizeof(int));

    for (int i = 0; i < c; i++)
    {
        ptr1[i] = (int *)malloc(c * sizeof(int));
        ptr2[i] = (int *)malloc(c * sizeof(int));
        ptr3[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x;
            scanf("%d", &x);
            ptr1[i][j] = x;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x;
            scanf("%d", &x);
            ptr2[i][j] = x;
        }
    }
    int i  = 0 , j = 0,k = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            ptr3[i][j] = 0;
            for (k = 0; k < c; k++)
            {
                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
            }
            printf("%d ",ptr3[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++)
    {
        free(ptr1[i]);
        free(ptr2[i]);
        free(ptr3[i]);
    }

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}