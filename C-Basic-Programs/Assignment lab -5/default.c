// C++ program to check if given array is has
// any even number
#include <stdio.h>

bool checkIfAnyEven(int arr[], int n)
{
	bool flag = false;
	for (int i=0; i<n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
int arr[] = {1, 3, 2, 5, 6, 7};
int n = sizeof(arr)/sizeof(arr[0]);
if (checkIfAnyEven(arr, n))
	printf("Yes");
else
	printf("no");
}
