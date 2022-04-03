#include<stdio.h>
#include<string.h>

struct book{
  char title[30];
  char author[30];
  int cost;
  int year;
};

void spec1(struct book b[], int n){
  for(int i=0;i<n;i++)
    if(!strcmp(b[i].title,"computer") && b[i].cost<500)
      printf("%s %s %d %d\n",b[i].title,b[i].author,b[i].cost,b[i].year);
}

void spec2(struct book b[], int n){
  char x[10];
  printf("Enter the auther's name whose book you want :-");
  scanf("%s",&x);
  for(int i=0;i<n;i++)
    if(!strcmp(b[i].author,x))
      printf("%s %s %d %d\n",b[i].title,b[i].author,b[i].cost,b[i].year);
}

void spec3(struct book b[], int n){
  int y;
  printf("Enter the year of published book that you want: ");
  scanf("%d",&y);
  for(int i=0;i<n;i++)
    if(b[i].year>=y)
      printf("%s %s %d %d\n",b[i].title,b[i].author,b[i].cost,b[i].year);
}

int main()
{
  int n;
  printf("Enter the number of books --> ");
  scanf("%d",&n);
  struct book b[n];
  printf("Enter the details (title, author, cost, year):\n");
  for(int i=0;i<n;i++){
    printf("Book %d --> ",i+1);
    scanf("%s%s%d%d",&b[i].title,&b[i].author,&b[i].cost,&b[i].year);
  }

  spec1(b , n);
  spec2(b , n);
  spec3(b , n);
  return 0;
}
