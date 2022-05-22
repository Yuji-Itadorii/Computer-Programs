#include <stdio.h>
int count;
struct student
{
    int student_name, student_roll_no, total_marks;
};

void merge(struct student arr[] , int l , int m , int r){
    int n1 = m-l+1 , n2 = r-m;
    int left[n1] , right[n2];
    for( int i = 0 ; i<n1 ; i++){
        left[i] = arr[l+i].student_roll_no;
    }

    for(int  i = 0 ; i<n2 ; i++){
        right[i] = arr[m+1+i].student_roll_no;
    }
    int i =0 , j=0 , k=l;
    while (i<n1 && j <n2)
    {
        count++;
        if (left[i]<=right[j])
        {
            arr[k].student_roll_no = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k].student_roll_no = right[j];
            j++;
            k++;
        }
    }

    while (i<n1)
    {
        arr[k].student_roll_no = left[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k].student_roll_no = right[j];
        j++;
        k++;
    }
    
    
}

void mergeSort(struct student arr[] , int l ,int r){
    if (l<r)
    {
        // count++;
        int m = l + (r-l)/2;
        mergeSort(arr , l , m);
        mergeSort(arr , m+1 , r);
        merge(arr, l ,m ,r);
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

    printf("\n the no. of comparisons  : %d", count);

    return 0;
}