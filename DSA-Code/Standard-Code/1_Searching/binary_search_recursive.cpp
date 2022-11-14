#include <iostream>
using namespace std;
int Binary_search_recursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        Binary_search_recursive(arr, low, mid - 1, key);
    else
        Binary_search_recursive(arr, mid + 1, high, key);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << Binary_search_recursive(arr, 0, 4, 3);
    return 0;
}