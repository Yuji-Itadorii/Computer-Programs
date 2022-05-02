//  create class student(Rollno, fee, Name) and create object array, add students and delete students, Rollno should be auto increment?

#include<iostream>
using namespace std;
class student{
    int rollno;
    int fee;
    string name;
    static int count;
    public:

    void set(int a , string s){
        fee = a;
        name = s;
        rollno = count;
        count++;
    }

    void display(){
        cout<<"Roll no is : "<<rollno<<endl;
        cout<<"Fee is : "<<fee<<endl;
        cout<<"Name is : "<<name<<endl;
    }
    // friend void delete_student();
};

// void delete_student( int *size, student arr[]){
//     int r;
//     cout<<"Enter the roll no. of the student : ";
//     cin>>r;
//     for (int i = r-1; i < *size; i++)
//     {
//         arr[i]=arr[i+1];
//         arr[i].count = arr[i].count-1;
//     }
//     *size = *size-1; 
//     }

int student ::count=1;
int main(){
    int size;
    cout<<"Enter the number of student : ";
    cin>>size;
    student arr[size];

    for (int i = 0; i < size; i++)
    {
        int F ;
        cout<<"enter the fees of student no. : "<<i+1<<endl;
        cin>>F;
        string S;
        cout<<"enter the name of student no. : "<<i+1<<endl;
        cin>>S;
        arr[i].set(F,S);
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i].display();
        cout<<endl;
    }

    return 0;
}