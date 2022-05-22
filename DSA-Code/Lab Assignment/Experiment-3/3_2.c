#include <stdio.h>
int count;
int compa;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
                compa++;
            }
        }
        count++;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {5,1,3,4,2};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\nThe number of swap: %d", count);
    printf("\nThe number of comparison are : %d", compa);

    return 0;
}