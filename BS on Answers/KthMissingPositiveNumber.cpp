/**
 * You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
 * Find the 'kth' positive integer missing from 'vec'.
 * 
 * Example 1:
 * Input Format: vec[]={4,7,9,10}, k = 1
 * Result: 1
 * Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. 
 * Since 'k' is 1, the first missing element is 1.
 * 
 * Example 2:
 * Input Format: vec[]={4,7,9,10}, k = 4
 * Result: 5
 * Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. 
 * Since 'k' is 4, the fourth missing element is 5.
 */

#include <bits/stdc++.h>
using namespace std;

int findMissing(vector<int> vec, int n, int k) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if(missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + k;
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

    int k;
    cout << "Enter the position of missing number : ";
    cin >> k;

    int missing = findMissing(arr, n, k);

    cout << "The missing number is : " << missing << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array
 * Reason : We are using the Binary Search Algorithm
 * 
 * Space Complexity : O(1)
 * Reason : We are not using any extra data structure
 */