#include <stdio.h>
int count;
void selectionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            count++;
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[] = {1, 3, 5, 6, 2};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\nThe number of comparison are : %d", count);

    return 0;
}