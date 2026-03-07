#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Naive Approach :- It takes O(n*m) times and O(n*m) space
vector<vector<int>> TransposeMatrix(vector<vector<int>>& mat){

    int rows = mat.size();
    int cols = mat[0].size();

    // Creating a result Matrix of Size cols * rows to  store the result
    vector<vector<int>> Tmat(cols , vector<int>(rows));


    // Fill the Transpose Matrix by Swapping Rows and Columns
    for(int i=0 ; i<rows ; i++){
        for(int j=0; j<cols ; j++){
            Tmat[j][i] = mat[i][j];
        }
    }

    return Tmat;
}

// Better approach :- It takes O(n*m) times and O(1) constant space
// Approac:- Just Swap the Upper Traingular Matrix with the Lower traingular Matrix

vector<vector<int>>  TranspMatrix(vector<vector<int>> &mat){

    int n = mat.size();

    for(int i = 0; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            swap(mat[i][j] , mat[j][i]);
        }
    }
    return mat;
}


int main() {
    vector<vector<int>> mat = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };

    // Calling approach-1
    // vector<vector<int>> res = TransposeMatrix(mat);

    // Calling approach-2
    vector<vector<int>> res = TranspMatrix(mat);

    for (auto& row : res) {
        for (auto& elem : row) {
            cout << elem << ' ';  
        }
        cout << "\n";  
    }

    return 0;
}