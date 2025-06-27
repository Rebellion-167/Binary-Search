/**
 * Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of 
 * columns, find the median in the given matrix.
 * 
 * Example 1:
 * Input Format:M = 3, N = 3, 
 * matrix[][] = 1 4 9 
 *              2 5 6
 *              3 8 7
 * Result: 5                 
 * Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 
 * 9. So, median = 5
 *           
 * Example 2:
 * Input Format:M = 3, N = 3, 
 * matrix[][] = 1 3 8 
 *              2 3 4
 *              1 2 5
 * Result: 3                 
 * Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 
 * 8. So, median = 3
 */

#include <bits/stdc++.h>
using namespace std;

//Implementing Upper Bound
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > x) {
            ans = mid;
            //looking for smaller index on the left
            high = mid - 1;
        } else {
            //looking on the right
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>>& mat, int x) {
    int cnt = 0;
    for(int i=0;i<mat.size();i++) {
        cnt += upperBound(mat[i], x);
    }
    return cnt;
}

int findMedian(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    int low = INT_MAX, high = INT_MIN;

    //pointing low and high
    for(int i=0;i<n;i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int req = (n * m) / 2;
    while(low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(mat, mid);
        if(smallEqual <= req) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;

    vector<vector<int>> mat;

    cout << "Enter elements row-wise : " << endl;
    for(int i=0;i<n;i++) {
        vector<int> tempo;
        for(int j=0;j<m;j++) {
            int temp;
            cin >> temp;
            tempo.push_back(temp);
        }
        mat.push_back(tempo);
    }

    int median = findMedian(mat);

    cout << "The median is : " << median << endl;

    return 0;
}

/**
 * Time Complexity: O(log(10^9)) X O(M(logN)), where M = number of rows in the given
 * matrix, N = number of columns in the given matrix
 * Reason: Our search space lies between [0, 10^9] as the min(matrix) can be 0 and the 
 * max(matrix) can be 10^9. We are applying binary search in this search space and it 
 * takes O(log(10^9)) time complexity. Then we call countSmallEqual() function for every 
 * ‘mid’ and this function takes O(M(logN)) time complexity.
 * 
 * Space Complexity : O(1) as we are not using any extra space
 */