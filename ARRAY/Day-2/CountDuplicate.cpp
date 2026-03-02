// Duplicates Element in the Array

//Naive approach :- Using O(n) Time and O(n) space

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> FindDuplicates(vector<int> &arr ){

    vector<int> ans;

    for(int i = 0 ; i<arr.size() ; i++ ){
        int count = 0;

        // Check if  element is already added or not.
        for(auto &it : ans){
            if(arr[i] == it)
            count++;
            break;
        }

        //If element is already added  skip checking.
        if(count) continue;


        // Check  if  current element again appear in the rest of the array

        for(int j=i+1; j<arr.size() ; j++){
            if(arr[i] == arr[j]){
                count++;
                break;
            }
        }

        // If element found push  it  into  the result
        if(count) ans.push_back(arr[i]);
    }

    return ans;
}

/// Using Better Approach:- Time complexity = O(n * log n) and  space:- O(n)

vector<int> FindDuplicate(vector<int> &arr){

    // Sort the whole  array from the beginning to the end

    sort(arr.begin() , arr.end());

    vector<int> ans;

    for(int i = 0 ;i<arr.size();i++){
        
        // Check if the current element is equal  to previous element
        if(arr[i] == arr[i-1]){

            if(ans.empty() || ans.back() != arr[i]){
                ans.push_back(arr[i]);
            }
        }
    }

    return ans;
}

// Using Better Approach:- Negating the Value of the array
//Time Complexity:- O(n) and Space Complexity :- O(n)

vector<int> FindDupli(vector<int> &arr){

    vector<int> ans;

    for(int i= 0 ; i<arr.size() ; i++){

        int idx = abs(arr[i] - 1);

        if(arr[idx] > 0){

            arr[idx] = -arr[idx];
        }
        else{
            ans.push_back(abs(arr[i]));
        }
    }

    return ans;

}

int main(){
    vector<int> arr = {2 , 3, 1 , 2 , 3};

    cout<<"Using Naive Approach:- ";
    vector<int> res = FindDuplicates(arr);

    for(int ele : res){
        cout<<ele<<" ";
    }

    cout<<endl;

    cout<<"Using Better Approah:- ";
    vector<int> result = FindDuplicate(arr);
    for(int element: result){
        cout<<element<<" ";
    }

    cout<<endl;

    cout<<"Using Negating Making Approach:-";
    vector<int> ans = FindDupli(arr);
    for(int answer : ans){
        cout<<answer<<" ";
    }

    cout<<endl;
    
    return 0;

}


