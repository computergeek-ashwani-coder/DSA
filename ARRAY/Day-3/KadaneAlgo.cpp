// Maximum Subarray Sum(Naive Approach)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindMaximumSubarray(vector<int> &arr){

    int res =  arr[0];

    // Outer Loop for the starting point of the subarray
    for(int i = 0; i<arr.size(); i++){

        int currsum = 0;

        // Inner Loop for the Ending Point of the Subarray
        for(int j= i ; j< arr.size() ; j++){
            currsum = currsum + arr[j];
        }

        // Update Res if the Current Sum is Greater than res
        res = max(currsum , res);
    }

    return res;

}

// Using Better Approach Takes:- TimeComplexity: O(n) and spaceComplexity: O(n)
int FindMaxSubArray(vector<int> &arr){
    int res = arr[0];
    int maxending = arr[0];

    // Traverse the array from left to right
    for(int i= 1 ; i < arr.size(); i++){

        maxending = (maxending + arr[i] > arr[i]) ? maxending + arr[i] : arr[i];

        res = (res > maxending) ? res : maxending;
    }

    return res;
} 



int main(){
    vector<int> arr = {2 , 3, - 8 , 7 , -1 , 2 , 3};
    cout<<FindMaximumSubarray(arr)<<endl;
    cout<<FindMaxSubArray(arr)<<endl;
    return 0;
}