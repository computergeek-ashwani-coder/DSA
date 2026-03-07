// Rotate Square Matrix By 90Degree CounterClockwise
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Naive Approach:- It takes O(n^2) Time and O(n^2) Space..
void RotateMatrix(vector<vector<int>> &mat)
{

    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));

    // Rotate the Matrix 90Degree CounterClockwise
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            res[n - j - 1][i] = mat[i][j];
        }
    }

    // Copy the entire Matrix back to the Original Matrix
    mat = res;
}


// Approach:2 Reversing Rows and Transposing..It takes O(n^2) times and O(n) Space
// Steps to Solve the Problem.
// Step:1 Suppose we have given a 4*4 Square Matrix
// Step:2 Reverse each Row of the Square Matrix
// Step:3 Transpose the Square Matrix for the result.

void rotateMatrix(vector<vector<int>>& mat){
    int n = mat.size();

    // Reverse the Each row of the Matrix
    for(int i=0 ;i<n ; i++){
        reverse(mat[i].begin() , mat[i].end());
    }

    // Performing Transpose
    for(int i=0; i< n ; i++){
        for(int j=i+1 ; j < n ; j++){
            swap(mat[i][j] , mat[j][i]);
        }
    }
}
int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    RotateMatrix(mat);

     for (auto &row : mat)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout<<endl;
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    rotateMatrix(mat1);

    for (auto &row : mat1)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}