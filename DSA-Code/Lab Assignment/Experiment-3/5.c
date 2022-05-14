#include <stdio.h>
int count;
struct student
{
    int student_name, student_roll_no, total_marks;
};

void merge(struct student arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        
        if (L[i].student_roll_no <= R[j].student_roll_no)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        count++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct student arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void dispaly(int size, struct student arr[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i].student_roll_no);
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    struct student arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i].student_roll_no);
    }

    mergeSort(arr, 0, size - 1);

    dispaly(size, arr);

    printf("\n the time complexity is : %d", count);

    return 0;
}