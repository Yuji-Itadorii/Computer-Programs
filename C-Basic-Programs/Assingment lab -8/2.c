#include<stdio.h>


struct student{
  char name[30];
  int rno;
  int marks;
  int fee;
};

void Topper(struct student arr[],int n){
  int max=0;
  for(int i=0;i<n;i++){
    if(arr[max].marks<arr[i].marks) max=i;
  }
  printf("\nDetails of the topper:\n");
  printf("\nName --> %s", arr[max].name);
  printf("\nRoll --> %d", arr[max].rno);
  printf("\nMarks --> %d", arr[max].marks);
  printf("\nFee --> %d\n", arr[max].fee);
}

void greater(struct student arr[],int n , int mark_avg){
  printf("\nStudents having marks greater than avg marks:\n");
  for(int i=0;i<n;i++){
    if(arr[i].marks>mark_avg){
      printf("\nName --> %s", arr[i].name);
      printf("\nRoll --> %d", arr[i].rno);
      printf("\nMarks --> %d", arr[i].marks);
      printf("\nFee --> %d\n", arr[i].fee);
    }
  }
}

void FEE(struct student arr[],int n){
  int flag = 0;
  printf("\nStudents who have not paid their fees: ");
  for(int i=0;i<n;i++){
    if(arr[i].fee<=0){
      flag = 1;
      printf("\nName --> %s", arr[i].name);
      printf("\nRoll --> %d", arr[i].rno);
      printf("\nMarks --> %d", arr[i].marks);
      printf("\nFee --> %d\n", arr[i].fee);
    }
  if (flag == 0)
    printf("None");
  }
}

int main(){
  int n , mark_avg = 0;
  printf("Enter the number of students --> ");
  scanf("%d",&n);
  struct student arr[n];
  for(int i=0;i<n;i++){
    printf("\nStudent %d:\n",i+1);
    printf("Name --> ");
    scanf("%s", &arr[i].name);
    printf("Roll --> ");
    scanf("%d", &arr[i].rno);
    printf("Marks --> ");
    scanf("%d", &arr[i].marks);
    printf("Fee --> ");
    scanf("%d", &arr[i].fee);
  }
  for (int i = 0; i < n; i++)
  {
     mark_avg+=arr[i].marks;
  }
  mark_avg/=n;
  greater(arr,n , mark_avg);
  Topper(arr,n);
  FEE(arr,n);
  return 0;
}
