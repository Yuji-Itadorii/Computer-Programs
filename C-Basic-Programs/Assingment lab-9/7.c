#include<stdio.h>
#include<math.h>
int main(){
    // A =  (1/2) [x1 (y2 – y3 ) + x2 (y3 – y1 ) + x3(y1 – y2)]
    int x1,y1,x2,y2,x3,y3;
    float area;
    printf("Enter the first cordinate : \n");
    scanf("%d %d",&x1,&y1);
    printf("Enter the second cordinate : \n");
    scanf("%d %d",&x2,&y2);
    printf("Enter the third cordinate : \n");
    scanf("%d %d",&x3,&y3);
    
    area = 0.5*(x1*(y2-y3) + y1 *(x2-x3 ) + (x2*y3-x3*y2));

    if (area==0)
    {
        printf("The coordinates are in line!");
    }
    else{
        printf("The coordinates are not in line!");
    }
    
    


    return 0;
}