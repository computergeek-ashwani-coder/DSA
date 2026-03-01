// Rotate the  array k times
#include <iostream>
#include <vector>
using namespace std;

void rotatedarray(vector<int> &arr, int n , int k)
{

    int  i, j;

    k = k % n;

    if (n == 0)
        return;

    // Reverse the last K elements
    for (i = n - k, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //    Reversing the first n-k elements
    for (i = 0, j = n - k - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //    Reverse the Entire Array
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int n = arr.size();

    int k = 2;

    rotatedarray(arr, n , k);

    // printing the reversed array
    cout << "Rotated Array::- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}