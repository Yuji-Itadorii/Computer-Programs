#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucket_sort(int arr[] , int n , int k ){
    int max_val = arr[0];
    for (int i = 0; i < n; i++)
    {
        max_val = max(arr[i] , max_val);
    }

    max_val++;

    vector<int> bkt[k];

    for(int i = 0 ; i<n ; i++){
        int bi = (k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }

    for(int i = 0 ; i< k ; i++){
        sort(bkt[i].begin() , bkt[i].end());
    }

    int index= 0 ;

    for(int i = 0 ; i< k ; i++){
        for(int j = 0 ; j< bkt[i].size() ; j++){
            arr[index++] = bkt[i][j];
        }
    }
    
}

int main(){
    int n = 7;
    int k = 9;
    int arr[] = {4 , 5, 6, 1 , 2, 3,8};

    bucket_sort(arr , n , k);

    for(int x :arr){
        cout<<x<<" ";
    }


    return 0;
}