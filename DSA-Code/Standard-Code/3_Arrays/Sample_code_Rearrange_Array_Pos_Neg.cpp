#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rightRotate(vector<int> &arr, int outofplace, int cur)
    {
        int tmp = arr[cur];
        for (int i = cur; i > outofplace; i--)
            arr[i] = arr[i - 1];
        arr[outofplace] = tmp;
    }

    vector<int> rearrangeArray(vector<int>& arr) {

        // vector<int> arr(nums.begin() , nums.end());

        int n = arr.size();
        int outOfPlace = -1;
        for(int i = 0 ; i< n ; i++){
            if(outOfPlace != -1){
                if((arr[outOfPlace]>=0 && arr[i]<0) || (arr[outOfPlace]<0 && arr[i]>=0)){
                    rightRotate (arr,outOfPlace , i);

                    if((i-outOfPlace)>=2){
                        outOfPlace += 2;
                    }
                    else{
                        outOfPlace = -1;
                    }
                }
            }
            else{
                if((arr[i]<0 && i%2==0) || (arr[i]>=0 && i%2==1)){
                    outOfPlace = i;
                }
            }
        }

        return arr;
    }
};

int main(){

    int arr[] = {3 , 2, -1 , 4, -5 , -9};
    
    // Answer will be :- {3 , -1 , 2, -5 , 4, -9} 
    return 0;
}