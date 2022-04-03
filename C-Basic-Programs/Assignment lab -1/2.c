#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    int radius_circle ;
    float area , perimetre;
    // Area and perimeter of Circle

    printf("Enter the value of radius : \n");
    scanf("%d",&radius_circle);
    area = 3.14*radius_circle*radius_circle;
    printf("The value of area of circle : %f \n" , area);
    perimetre = 2*3.14*radius_circle;
    printf("The value of perimeter of circle : %f \n" , perimetre);

    printf("\n");
    // Area and perimeter of Triangle

    int side1_triangle,side2_triangle,side3_triangle  , s;
    printf("Enter the value of 3 sides of triangle  : \n");
    scanf("%d %d %d",&side1_triangle , &side2_triangle , &side3_triangle);
    s= (side1_triangle+side2_triangle+side3_triangle)/2;
    area= sqrt((s*(s-side1_triangle)*(s-side2_triangle)*(s-side3_triangle)));
    printf("The value of area of triangle : %f \n" , area);
    perimetre=side1_triangle+side2_triangle+side3_triangle;
    printf("The value of perimeter of triangle is  : %f \n" , perimetre);


    printf("\n");
    // Area and perimeter of Rectangle 

    int lenght_rectangle , breadth_rectangle;
    printf("Enter the value of lenght and breath of rectangle : \n");
    scanf("%d %d",&lenght_rectangle , &breadth_rectangle);
    area = lenght_rectangle*breadth_rectangle;
    printf("The value of area of rectangle : %f \n" , area);
    perimetre=2*(lenght_rectangle+breadth_rectangle);
    printf("The value of perimeter of rectangle is  : %f \n" , perimetre);

    printf("\n");
    // Area and perimeter of square 

     int side_square;
    printf("Enter the value of side of square : \n");
    scanf("%d",&side_square);
    area = side_square*side_square;
    printf("The value of area of square : %f \n" , area);
    perimetre=4*side_square;
    printf("The value of perimeter of rectangle is  : %f \n" , perimetre);
    
    return 0 ;
}