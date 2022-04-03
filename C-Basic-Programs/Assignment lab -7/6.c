#include <stdio.h>
int prime(int a)
{
    int count = 0;
    if (a == 2)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i < a; i++)
        {
            if (a % i == 0)
            {
                return 0;
                break;
            }
            else
            {
                count++;
            }
        }
    }
    if (count == a - 2 && a != 2)
    {
        return 1;
    }
}
int main()
{
    int a;
    printf("Enter the number : ");
    scanf("%d", &a);

    if (prime(a))
    {
        printf("Yes prime number\n");
    }
    else{
        printf("Not a prime number\n");
    }

    int x;
    printf("enter the value of n : ");
    scanf("%d",&x);

    for (int  i = 2; i <=x; i++)
    {
        if(prime(i)){
        printf("%d ", i);
        }
    }

    return 0;
}