// Rotate the Aray k times  
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// Naive Approach 
void rotateclockwise(vector<int> &arr , int k){
    if(k == 0) return;

    int n = arr.size();
    if(n == 0 ) return;

    int temp = arr[n-1];

    for(int i= n-1 ; i > 0 ; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    rotateclockwise(arr , k-1);

}

void rotatedclockwise(vector<int>&arr , int k){

    int n = arr.size();
    if(n == 0) return;

     k = k % n ;

    int i , j;

    // Reverse the first n-k part of the array 
    for( i = 0 , j = n-k-1 ; i<j ; i++ ,j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Reverse the last part of the array
    for( i = n-k , j = n-1 ; i<j ; i++ , j--){
        int temp = arr[i];
        arr[i] =  arr[j];
        arr[j] = temp;
    }
    
    // Reverse the entire array
    for(i= 0 , j = n-1 ; i<j ; i++ , j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
     }
}

int main(){
    vector<int> arr1 = {1 , 2, 3, 4, 5};
    vector<int> arr2 = {1 , 2, 3, 4 ,5};
    int k = 3;

    rotateclockwise(arr1 , k);
    cout<<"Rotated Array Using Naive Approach :- ";
    for(int i = 0 ;i<arr1.size() ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    rotatedclockwise(arr2 , k);
    cout<<"Rotate Clockwise Using Better Approach:- ";
    for(int i = 0 ;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    return 0;
}