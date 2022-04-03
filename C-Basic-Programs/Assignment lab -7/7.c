#include <math.h>
#include <stdio.h>
int discriminant;
float root1, root2, realPart, imagPart;
int roots(int a, int b, int c)
{
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        return 1;
    }
    else if (discriminant == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int main()
{
    float a, b, c, discriminant;
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    switch (roots(a, b, c))
    {
    case 1:
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2f and root2 = %.2f", root1, root2);
        break;
    case 2:
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2f;", root1);
        break;
    case 3:
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2f+%.2fi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
        break;
    }
    return 0;
}