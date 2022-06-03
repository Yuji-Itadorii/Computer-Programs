#include<iostream>
using namespace std;
class Time {
    int h ; 
    int m ;
    int s ;
    string x ;
    bool check;
    public :

    int get_h(){ return h;}
    int get_m(){ return m;}
    int get_s(){ return s;}
    string get_x(){ return x;}
    bool get_check(){return check;}


    friend Time Function(int *p);

};

Time Function( int * p){
    Time t;
    if(*p>86400){
        t.check=false;
    }
    else{
        t.h = *p/3600;
        t.x = (*p<=43200)? "A.M" : "P.M"; 
        t.m = (*p%(60*60))/60;
        t.s = ((*p%(60*60))%60);
        t.check=true;
    }
    return t;
}

int main(){
    int time_sec ;
    cout<<"Enter the time in seconds :- ";
    cin>>time_sec;
    Time t = Function(&time_sec);

    if(t.get_check()==false){
        cout<<"Error Occur!!"<<endl;
    }
    else{
    cout<<"Time in hour , minute , second :- "<<t.get_h()<<" "<<t.get_m()<<" "<<t.get_s()<<" "<<t.get_x()<<endl; 
    }

    return 0;
}