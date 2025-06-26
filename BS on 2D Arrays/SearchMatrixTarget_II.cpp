/**
 * You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the 
 * number of rows and columns, respectively. The elements of each row and each column 
 * are sorted in non-decreasing order.
 * But, the first element of a row is not necessarily greater than the last element 
 * of the previous row (if it exists).
 * You are given an integer ‘target’, and your task is to find if it exists in the given 
 * 'mat' or not.
 * 
 * Examples : 
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],
 * [18,21,23,26,30]], target = 5
 * Output: true
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],
 * [18,21,23,26,30]], target = 20
 * Output: false
 */

#include <bits/stdc++.h>
using namespace std;

bool findTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0, col = m - 1;
    while(row < n && col >= 0) {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main() {
    int n,m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> matrix;

    cout << "Enter the elements in the matrix row-wise : " << endl;
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
 * Time Complexity: O(N+M), where N = given row number, M = given column number.
 * Reason: We are starting traversal from (0, M-1), and at most, we can end up being 
 * in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time 
 * complexity is O(N+M).
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */