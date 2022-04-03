#include <stdio.h>
int max3(int a, int b, int c)
{
    if (a >= b)
    {
        if (a >= c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else if (b >= c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
int main()
{
    int a = 49 , b = 9 , c = 1 ,d=0,e=8,f=5,g=7,h=3,i=2;
   
   int result1 = max3(a,b,c);
   int result2 = max3(d,e,f);
   int result3 = max3(g,h,i);

    printf("%d",max3(result1 , result2 , result3));
    return 0;
}