/**
 * You are given a sorted array arr of distinct values and a target value x. 
 * You need to search for the index of the target value in the array.
 * 
 * If the value is present in the array, then return its index. 
 * Otherwise, determine the index where it would be inserted in the array 
 * while maintaining the sorted order.
 * 
 * Example 1:
 * Input Format: arr[] = {1,2,4,7}, x = 6
 * Result: 3
 * Explanation: 6 is not present in the array. So, if we will insert 6 in the 
 * 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.
 * 
 * Example 2:
 * Input Format: arr[] = {1,2,4,7}, x = 2
 * Result: 1
 * Explanation: 2 is present in the array and so we will return its index i.e. 1.
 */

#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int>& arr, int m) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int m;
    cout << "Enter the value of m : ";
    cin >> m;

    int ind = findIndex(arr, m);

    cout << ind << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array (base is 2)
 * Space Complexity : O(1)
 */