#include <iostream>
using namespace std;
void mergeSort(int arr[], int size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        int min_ind = i ;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min_ind]>arr[j])
            min_ind=j;
        }
        swap(arr[min_ind],arr[i]);
    }
    
}
int main()
{
    int arr[] = {3, 4, 2, 8, 5};
    mergeSort(arr, 5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}