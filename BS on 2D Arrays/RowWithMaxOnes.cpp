/**
 * You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting 
 * of only 0s and 1s. All the rows are sorted in ascending order.
 * Your task is to find the index of the row with the maximum number of ones.
 * Note: If two rows have the same number of ones, consider the one with a smaller 
 * index. If there's no row with at least 1 zero, return -1.
 * 
 * Example 1:
 * Input Format: n = 3, m = 3, 
 * mat[] = 
 * 1 1 1
 * 0 0 1
 * 0 0 0
 * Result: 0
 * Explanation: The row with the maximum number of ones is 0 (0 - indexed).
 * 
 * Example 2:
 * Input Format: n = 2, m = 2 , 
 * mat[] = 
 * 0 0
 * 0 0
 * Result: -1
 * Explanation:  The matrix does not contain any 1. So, -1 is the answer.
 */

#include <bits/stdc++.h>
using namespace std;

int findRow(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int max_cnt = 0;
    int index = -1;
    for(int i=0;i<n;i++) {
        int cnt_ones = matrix[i].end() - lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        if(cnt_ones > max_cnt) {
            max_cnt = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> matrix;

    cout << "Enter the elements row-wise : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        matrix.push_back(tempo);
    }

    int ind = findRow(matrix);

    cout << "The row with maximum one is : " << ind << endl;

    return 0;
}

/**
 * Time Complexity: O(n X logm), where n = given row number, m = given column number.
 * Reason: We are using a loop running for n times to traverse the rows. Then we are 
 * applying binary search on each row with m columns.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 */