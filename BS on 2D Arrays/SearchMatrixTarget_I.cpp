/**
 * You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the 
 * number of rows and columns, respectively. The elements of each row are sorted in 
 * non-decreasing order. Moreover, the first element of a row is greater than the last 
 * element of the previous row (if it exists). You are given an integer ‘target’, and 
 * your task is to find if it exists in the given 'mat' or not.
 * 
 * Example 1:
 * Input Format: N = 3, M = 4, target = 8,
 * mat[] = 
 * 1 2 3 4
 * 5 6 7 8 
 * 9 10 11 12
 * Result: true
 * Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).
 * 
 * Example 2:
 * Input Format: N = 3, M = 3, target = 78,
 * mat[] = 1 2 4
 * 6 7 8 
 * 9 10 34
 * Result: false
 * Explanation: The ‘target' = 78 does not exist in the 'mat'. Therefore in the output,
 * we see 'false'.
 */

#include <bits/stdc++.h>
using namespace std;

bool findTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //Flattening a 2D array into 1D array(hypothetically)
    //and applying binary search
    int low = 0, high = n*m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        //Computing the row and column
        //For row - .../m
        //For column - ...%m
        int row = mid / m, col = mid % m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    int n,m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> matrix;

    cout << "Enter the elements in the matrix row-wise: " << endl;
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        matrix.push_back(tempo);
    }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    cout << boolalpha << findTarget(matrix, target);

    return 0;
}

/**
 * Time Complexity : O(log2(n * m)) where n and m are the number of rows and columns of 
 * the matrix. We are applying Binary Search Algorithm on the range [0...n*m]
 * 
 * Space Complexity : O(1) as no extra space is used
 */