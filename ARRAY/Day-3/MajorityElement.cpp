#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_Map>
using namespace std;

// Naive Approach : TimeComplexity: O(n) and SpaceComplexity : O(1)
int findMajorityelement(vector<int> &arr)
{

    // Loop to Select Each Element as a Candidate to Find Majority
    for (int i = 0; i < arr.size(); i++)
    {

        int count = 0;
        int n = arr.size();

        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > n / 2)
        {
            return arr[i];
        }
    }

    return -1;
}

// Better Approach:- TimeComplexity : O(n(logn)) and SpaceComplexity: O(1)
// Sorting the Array then Find the Majority Element
int findMajorElement(vector<int> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int candidate = arr[n / 2]; // Potential Majority Element

    int count = 0;
    for (int num : arr)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    if (count > n / 2)
    {
        return candidate;
    }

    // No Majority Element
    return -1;
}

// Better Approach : 2
// Using HashMap:- TimeComplexity O(n) and SpaceComplexity O(1)

int FindMajElement(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, int> CountMap;

    // Traverse the array and Count Occurences using HashMap
    for (int num : arr)
    {
        CountMap[num]++;

        if (CountMap[num] > n / 2)
        {
            return num;
        }
    }

    return -1;
}

// Main Function
int main()
{
    vector<int> arr = {4, 3, 4, 2, 4, 1, 4};
    cout << findMajorityelement(arr) << endl;
    cout << findMajorElement(arr) << endl;
    cout<<FindMajElement(arr)<<endl;

    return 0;
}
