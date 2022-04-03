#include<stdio.h>
int main(){
    while (1)
    {   
        char character;
        printf("Enter the character : ");
        scanf("%c",&character);
        if (character=='-')
        {   
            printf("Program Exited!");
            break;
        }
        else{
            printf("The ASCII value of %c is : %d\n",character,character);
        }
        
    }
    
    
    return 0;
}