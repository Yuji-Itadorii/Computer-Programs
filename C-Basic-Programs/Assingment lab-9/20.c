#include<stdio.h>
int main(){
    int x ,y;
    printf("Enter the value of x coordinate and y coordinate  : \n");
    scanf("%d %d",&x,&y);
    if (x==0 && y==0)
    {
        printf("Points are at the origin \n");
    }
    else if (x==0)
    {
        printf("Points are on the y axix \n");
    }
    else if (y==0)
    {
        printf("Points are on the x axix \n");
    }
    else if (x>0 && y>0)
    {
        printf("Points are in First quadrant \n");
    }
    else if (x<0 && y>0)
    {
        printf("Points are in second quadrant \n");
    }
    else if (x<0 && y<0)
    {
        printf("Points are in third quadrant \n");
    }
    else if (x>0 && y <0)
    {
        printf("Points are in fourth quadrant \n");
    }
    return 0;
}