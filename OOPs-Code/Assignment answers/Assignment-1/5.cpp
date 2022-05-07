//  create class student(Rollno, fee, Name) and create object array, add students and delete students, Rollno should be auto increment?

#include<iostream>
#include<vector>
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

    void addStudent(int f , string n){
        fee = f;
        name = n;
        rollno = count;
        count++;
    }
};

int student ::count=1;
int main(){
    int size;
    cout<<"Enter the number of student : ";
    cin>>size;
    vector <student> v(size);
    // student arr[size];

    for (int i = 0; i < v.size(); i++)
    {
        int F ;
        cout<<"enter the fees of student no. : "<<i+1<<endl;
        cin>>F;
        string S;
        cout<<"enter the name of student no. : "<<i+1<<endl;
        cin>>S;
        v[i].set(F,S);
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        v[i].display();
        cout<<endl;
    }

    return 0;
}