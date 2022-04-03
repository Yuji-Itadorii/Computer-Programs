#include<stdio.h>
#include<stdlib.h>

struct date
{
  int d;
  int m;
  int y;
};
int compare ( struct date d1 , struct date d2){
  if(d1.y>d2.y) return 1;
  else if(d1.y<d2.y) return 2;
  else
  {
    if(d1.m>d2.m) return 1;
    else if(d1.m<d2.m) return 2;
    else
    {
      if(d1.d>d2.d) return 1;
      else if(d1.d<d2.d) return 2;
      else printf("\nBoth dates are same");
      exit (0);
    }
  }

}

int main()
{
  struct date d1,d2;
  printf("Enter first date :-");
  scanf("%d%d%d",&d1.d,&d1.m,&d1.y);
  printf("Enter second date :-");
  scanf("%d%d%d",&d2.d,&d2.m,&d2.y);
  int x =compare(d1,d2);
  if (x==1)
  {
  printf("The recent date is:;- %d/%d/%d\n",d1.d,d1.m,d1.y);
  }
  else if (x==2){
  printf("The recent date is:;- %d/%d/%d\n",d2.d,d2.m,d2.y);
  }
  
  return 0;
}
