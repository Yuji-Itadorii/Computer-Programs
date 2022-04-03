#include<stdio.h>
int stringLength( char arr[]){
    int count = 0;
    while (arr[count]!='\0')
    {
        count++;
    }
    return count;
}
void stringCopy( char arr1[] , char arr2[]){
    for (int i = 0; i < stringLength(arr1); i++)
    {
        arr2[i]=arr1[i];
    }
}
int stringCompare( char arr1[] , char arr2[]){
    int count=0;
    for (int i = 0; i < stringLength(arr1); i++)
    {
        if (arr2[i]==arr1[i])
        {
            count++;
        }
        
    }

    if (count == stringLength(arr1))
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void stringReverse( char arr1[]){
    for (int i = 0; i < stringLength(arr1)/2; i++)
    {
        char temp = arr1[i]; 
        arr1[i]=arr1[stringLength(arr1)-1-i];
        arr1[stringLength(arr1)-1-i] = temp;
    }
}
int stringPalindrom(char arr[]){
    char s[10];
    stringCopy(arr , s);
    stringReverse(arr);
    if (stringCompare(arr , s))
    {
        return 1;
    }
    else{
        return 0 ;
    }
}
int main(){
    char s1[] = {"AbhbA"} ,s2[] = {"Rawat"};
    printf("%d\n",stringLength(s1));
    char s3[10];
    stringCopy(s1 , s3);
    printf("%s\n",s3);

    (stringCompare(s1 , s2))? printf("Same\n") : printf("Not Same\n") ;

    stringReverse(s2);
    printf("%s\n" , s2); 

    (stringPalindrom(s1))? printf("Palindrome\n") : printf("Not Palindrom\n") ;
    
    return 0;
}