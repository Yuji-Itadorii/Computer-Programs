#include<iostream>
using namespace std;
class Date{
    public:
    int d , m , y ;
    Date(int a , int b , int c){
        m = a ;
        d = b;
        y = c;
    } 
};

void Age_of_person(Date d1 , Date d2){
    int age = d1.y - d2.y;
    cout<<"The age of person is : "<<age<<endl;
}
int main(){
    int month , day , year ;
    cout<<"Enter the current date : \n";
    cin>>month>>day>>year;
    Date current(month , day , year);
    cout<<"Enter the date of birth : \n";
    cin>>month>>day>>year;
    Date DOB(month , day , year);

    Age_of_person(current , DOB);
    

    return 0;
}