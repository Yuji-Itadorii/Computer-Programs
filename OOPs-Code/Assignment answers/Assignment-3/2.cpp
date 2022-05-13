#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int arr[] = {1, 3, 9, 27, 81, 243, 729, 2187};
    srand(time(0));
    int c = (rand()%7)+1;

    cout<<arr[c]<<endl;
    
    


    return 0;
}