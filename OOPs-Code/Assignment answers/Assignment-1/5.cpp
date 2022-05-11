//  create class student(Rollno, fee, Name) and create object array, add students and delete students, Rollno should be auto increment?

#include<iostream>
#include<vector>
using namespace std;
class student{
    int fee;
    string name;
    public:
    int rollno;
    static int count;

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

    friend void delete_Student( student arr[] , int r , int *size);
};

void delete_Student( student arr[] , int r , int *size){
    if (r==*size)
    {
        *size = *size-1;
        return;
    }
    
    for (int i = 0; i < *size; i++)
    {
        if (i+1==r)
        {
            for (int j = i; j < *size-1; j++)
            {
                arr[j] = arr[j+1];
                arr[j].rollno = arr[j].rollno - 1;
            }
            *size = *size-1;
            return;
        }
        
    }
}

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
    
    for (int i = 0; i <size; i++)
    {
        arr[i].display();
        cout<<endl;
    }

    cout<<"Enter the roll no. that you want to delete : ";
    int r ;
    cin>>r;

    delete_Student(arr, r , &size);

    for (int i = 0; i < size; i++)
    {
        arr[i].display();
        cout<<endl;
    }

    return 0;
}