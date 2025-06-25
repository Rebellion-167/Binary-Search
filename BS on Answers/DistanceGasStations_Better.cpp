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

long double minimizeMaxDistance(vector<int>& arr, int k) {
    int n = arr.size(); //size of the array
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    //Inserting the first n - 1 elements into pq
    //with respective distance values:
    for(int i=0;i<n-1;i++) {
        pq.push({arr[i+1] - arr[i], i});
    }

    //Picking and placing k gas stations
    for(int gasStations = 1;gasStations <= k;gasStations++) {
        //Finding the maximum section
        //and inserting the gas station
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        //Inserting the current gas station
        howMany[secInd]++;

        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
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
 * Time Complexity: O(nlogn + klogn),  n = size of the given array, k = no. of gas 
 * stations to be placed.
 * Reason: Insert operation of priority queue takes logn time complexity. 
 * O(nlogn) for inserting all the indices with distance values and O(klogn) for 
 * placing the gas stations.
 * 
 * Space Complexity: O(n-1)+O(n-1)
 * Reason: The first O(n-1) is for the array to keep track of placed gas stations 
 * and the second one is for the priority queue.
 */