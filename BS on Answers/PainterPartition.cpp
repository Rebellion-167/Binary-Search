/**
 * Given an array/list of length ‘N’, where the array/list represents the boards and 
 * each element of the given array/list represents the length of each board. Some ‘K’ 
 * numbers of painters are available to paint these boards. Consider that each unit of 
 * a board takes 1 unit of time to paint. You are supposed to return the area of the 
 * minimum time to get this job done of painting all the ‘N’ boards under the constraint 
 * that any painter will only paint the continuous sections of boards.
 * 
 * Example 1:
 * Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
 * Result: 10
 * Explanation: We can divide the boards into 2 equal-sized partitions, so each 
 * painter gets 10 units of the board and the total time taken is 10.
 * 
 * Example 2:
 * Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
 * Result: 60
 * Explanation: We can divide the first 3 boards for one painter and the last board 
 * for the second painter.
 */

#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int>& arr, int time) {
    int partition = 1;
    int boards = 0;
    int n = arr.size();
    for(int i=0;i<n;i++) {
        if(boards + arr[i] <= time) {
            boards += arr[i];
        } else {
            partition++;
            boards = arr[i];
        }
    }
    return partition;
}

int findMinimumTime(vector<int>& boards, int k) {
    int n = boards.size();
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while(low <= high) {
        int mid = (low + high) / 2;
        int count = countPartitions(boards, mid);
        if(count > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter number of boards : ";
    cin >> n;

    vector<int> boards;
    cout << "Enter the length of each board : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        boards.push_back(temp);
    }
    
    int k;
    cout << "Enter number of painters : ";
    cin >> k;

    int time = findMinimumTime(boards, k);

    cout << "The minimum time is : " << time << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where M = sum - max + 1 where sum is the sum of all
 * elements of the array and max is the maximum element in the array. We are applying
 * Binary Search Algorithm
 * 
 * Space Complexity : O(1) since we are not using any extra space
 */