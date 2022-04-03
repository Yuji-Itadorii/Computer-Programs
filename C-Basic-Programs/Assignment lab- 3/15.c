#include <stdio.h>
#include <math.h>
int fac(int a ){
    int fact = 1 ;
    for (int i = 1; i < a; i++)
    {
    fact = fact*i;
    }
    return (float)fact;
    
}
void main()
{
	int x,sum,ctr;
	int i,n,m,mm,nn ;
	printf("Input the value of x :");
	scanf("%d",&x);
	printf("Input number of terms : ");
	scanf("%d",&n);
	sum =x; m=-1;
	printf("The values of the series: \n");
	printf("%d\n",x);
    for (i = 1; i < n; i++) 
    {
        ctr = (2 * i + 1);
        mm = pow(x, ctr);
        nn = (mm * m);
        float term ;
        term = nn/fac(ctr);
        printf("%d / %d = %f\n",nn , fac(ctr), term);
        sum = sum + term;
        m = m * (-1);
	}
	printf("\nThe sum = %d\n",sum);
}