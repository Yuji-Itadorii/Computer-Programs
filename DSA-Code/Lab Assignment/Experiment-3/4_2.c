#include <stdio.h>
int count;
void swap(int* a, int* b)
{
    count++;
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
		printf("\n");
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the random index of array as a povit : \n");
    int ran;
    scanf("%d",&ran);
    int temp = arr[ran];
    arr[ran]=arr[n];
    arr[n] = temp;
	quickSort(arr, 0, n - 1);
	printArray(arr, n);
    printf("\nThe number of swaps are : %d", count);
	return 0;
}

