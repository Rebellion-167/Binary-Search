/**
 * A peak element in a 2D grid is an element that is strictly greater than all of 
 * its adjacent neighbors to the left, right, top, and bottom.
 * Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find 
 * any peak element mat[i][j] and return the length 2 array [i,j].
 * You may assume that the entire matrix is surrounded by an outer perimeter with 
 * the value -1 in each cell.
 * 
 * Examples : 
 * 
 * Input: mat = [[1,4],[3,2]]
 * Output: [0,1]
 * Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable 
 * answers.
 * 
 * Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
 * Output: [1,1]
 * Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable 
 * answers.
 * 
 * No two adjacent cells are equal.
 */

#include <bits/stdc++.h>
using namespace std;

int findMaxElement(vector<vector<int>>& matrix, int col) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxEle = -1;
    int ind = -1;
    for(int i=0;i<n;i++) {
        if(matrix[i][col] > maxEle) {
            maxEle = matrix[i][col];
            ind = i;
        }
    }
    return ind;
}
vector<int> findPeak(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    //Applying Binary Search:
    int low = 0, high = m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int row = findMaxElement(matrix, mid);
        int left = mid - 1 >= 0 ? matrix[row][mid - 1] : -1;
        int right = mid + 1 < m ? matrix[row][mid + 1] : -1;
        if(matrix[row][mid] > left && matrix[row][mid] > right) {
            return {row, mid};
        } else if (matrix[row][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> mat;

    cout << "Enter the elements row-wise : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        mat.push_back(tempo);
    }

    vector<int> ind = findPeak(mat);
    cout << "The coordinates of the peak element are : " << ind[0] << " " << ind[1] << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where N are the number of rows and M are the number
 * of columns. We are applying Binary Search Algorithm on the range [0...M] and for 
 * every iteration, we are scanning all rows.
 * 
 * Space Complexity : O(1) as no extra space is used.
 */