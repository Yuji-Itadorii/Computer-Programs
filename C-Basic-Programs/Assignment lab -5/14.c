#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of student: ");
    scanf("%d" , &n);
    
    int arr1[n][3];
    printf("Enter the marks of student--\n");
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            if(j==0){
                printf("Enter Physics Marks of Roll No %d : ",i);
            }
            else if (j==1)
            {
                printf("Enter Maths Marks of Roll No %d : ",i);
            }
            else{
                 printf("Enter Chemistry Marks of Roll No %d : ",i);
            }
            scanf("%d",&arr1[i][j]);
        }
        
    }   

    //tital marks of each students

    for (int i = 0; i < n; i++)
    {
        printf("The total marks of Student %d is : %d \n", i , (arr1[i][0]+arr1[i][1]+arr1[i][2]));
    }

    //Average of each subject 
    float sum1 = 0 , sum2 = 0 , sum3 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + arr1[i][0];
        sum2 = sum2 + arr1[i][1];
        sum3 = sum3 + arr1[i][2];
    }
    
    printf("The average marks in Physics , Maths and Chemistry respectively are : %0.2f  , %0.2f  and %0.2f\n",(sum1/n),(sum2/n),(sum3/n));

    return 0;
}