#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> arr = {1 , 2 , 4, 5, 3 , 0};

    int start = 0 ; 
    int end = arr.size()-1;

    while(start < end){

        //Swap the elements
        int temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;

        start++;
        end--;
    }

    // Printing the reversed array
    cout<<"Reversed Array: "<<endl;
    for(int i=0 ; i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}