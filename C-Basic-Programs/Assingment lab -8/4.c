#include <stdio.h>
struct bank
{
  char acc_no[20];
  char name[30];
  int balance;
  int lt_amount;
  int d ;
  int  m ;
  int y;
};

void find(struct bank arr[] , int n ){
  for (int i = 0; i < n; i++)
  {
    if (arr[i].acc_no[0] == '1' && arr[i].acc_no[1] == '0' && arr[i].acc_no[2] == '1' )
    {
      printf("candidate no. %d is the student of NIT kkr \n",i+1);
    }
  }
}
void search(struct bank arr[] , int n ){
  for (int i = 0; i < n; i++)
  {
    if (arr[i].y<=2021 )
    {
      printf("%s\n",arr[i].name);
    }
  }
}



int main (){
  printf("Enter the value pf n : \n");
  int n ; 
  scanf("%d",&n);
  struct bank arr[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter details of no . %d\n",i+1);
  printf("Enter the Account number ,  name , Balance , left amount ,  last date : \n");
    scanf("%s%s%d%d%d%d%d",&arr[i].acc_no ,&arr[i].name ,&arr[i].balance ,&arr[i].lt_amount ,&arr[i].d ,&arr[i].m ,&arr[i].y );
  }
  find(arr , n);
  search(arr , n);
  
  return 0 ;
}
