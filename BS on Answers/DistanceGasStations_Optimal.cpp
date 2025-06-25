/**
 * You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer 
 * positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. 
 * You have to place 'k' new gas stations on the X-axis. You can place them anywhere 
 * on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' 
 * be the maximum value of the distance between adjacent gas stations after adding k 
 * new gas stations.
 * Find the minimum value of ‘dist’
 * Note: Answers within 10^-6 of the actual answer will be accepted.
 * 
 * Example 1:
 * Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
 * Result: 0.5
 * Explanation: One of the possible ways to place 4 gas stations is 
 * {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas 
 * stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there 
 * is no possible way to add 4 gas stations in such a way that the value of ‘dist’
 * is lower than this. 
 * 
 * Example 2:
 * Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
 * Result: 1
 * Explanation: One of the possible ways to place 1 gas station is 
 * {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas 
 * stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there 
 * is no possible way to add 1 gas station in such a way that the value of ‘dist’ 
 * is lower than this. 
 */

#include <bits/stdc++.h>
using namespace std;

int numberOfGasStations(vector<int>& arr, long double dist) {
    int n = arr.size();
    int cnt = 0;
    for(int i=1;i<n;i++) {
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((arr[i] - arr[i-1]) == (dist * numberInBetween)) {
            //If exactly divisible, decrease by 1
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
long double minimizeMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    //Finding the max distance between consecutives
    for(int i=0;i<n-1;i++) {
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }

    //Applying Binary Search
    long double diff = 1e-6;
    while(high - low > diff) {
        long double mid = (low + high) / 2;
        int cnt = numberOfGasStations(arr, mid);
        if(cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    int n;
    cout << "Enter the number of gas stations : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the position of gas stations : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k;
    cout << "Enter the number of new gas stations : ";
    cin >> k;

    long double maxDis = minimizeMaxDistance(arr, k);
    
    cout << fixed << setprecision(6);
    cout << "The maximum distance between gas stations is : " << maxDis << endl;

    return 0;
}

/**
 * Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of 
 * the answer space.
 * Reason: We are applying binary search on the answer space. For every possible answer, 
 * we are calling the function numberOfGasStationsRequired() that takes O(n) time 
 * complexity. And another O(n) for finding the maximum distance initially.
 * 
 * Space Complexity: O(1) as we are using no extra space to solve this problem.
 */
