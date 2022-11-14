#include <iostream>
using namespace std;

int lpartition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int hpartition(int arr[] , int l , int h){
    int pivot = arr[l];
    int i = l-1;
    int j = h+1;
    while(true){
        do
        {
            i++;
        } while (arr[i]<pivot);

        do
        {
            j--;
        } while (arr[j]>pivot);

        if(i>=j){
            return j;
        }
        
        swap(arr[i] , arr[j]);
        
    }
}

void quickSort(int arr[], int l , int h)
{
    if(l<h){
        int p = lpartition(arr , l , h);
        quickSort(arr , l , p-1);
        quickSort(arr , p+1 , h);
    }
}
// void quickSort(int arr[], int l , int h)
// {
//     if(l<h){
//         int p = hpartition(arr , l , h);
//         quickSort(arr , l , p);
//         quickSort(arr , p+1 , h);
//     }
// }
int main()
{
    int arr[] = {3, 4, 2, 8, 5};
    quickSort(arr, 0 , 4);

    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}