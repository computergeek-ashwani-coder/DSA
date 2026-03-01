// Kadane's Algorithm
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kadaneAlgo(vector<int> &arr){

    int res = arr[0];

    int maxending = arr[0];

    for(int i = 1 ; i<arr.size() ; i++){
        
        maxending = max(arr[i] , maxending + arr[i]);

        res = max(res , maxending);
    }

    return res;
}

int main(){
    vector<int> arr = {-2 , 1 , -3 , 4 , -1 , 2 , 1 , -5 , 4};
    
    int maxending = kadaneAlgo(arr);

    cout<<"Maximum sum of the Subarray is: " <<maxending<<endl;
    return 0;

}