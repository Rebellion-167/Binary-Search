/**
 * Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ 
 * into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. 
 * Your task is to return the minimized largest sum of the split.
 * A subarray is a contiguous part of the array.
 * 
 * Example 1:
 * Input Format: N = 5, a[] = {1,2,3,4,5}, k = 3
 * Result: 6
 * Explanation: There are many ways to split the array a[] into k consecutive subarrays. 
 * The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where 
 * the largest sum among the three subarrays is only 6.
 * 
 * Example 2:
 * Input Format: N = 3, a[] = {3,5,1}, k = 3
 * Result: 5
 * Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., 
 * [3], [5], and [1]. The largest sum among these subarrays is 5.
 */

#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int sum) {
    int count = 1; //To count the number of subarrays
    int subarraySum = 0; //To store the sum of each subarray
    int n = arr.size();
    for(int i=0;i<n;i++) {
        if(subarraySum + arr[i] <= sum) {
            //Adding to the current subarray
            subarraySum += arr[i];
        } else {
            //Creating another subarray
            count++;
            subarraySum = arr[i];
        }
    }
    return count;
}

int largetSum(vector<int> arr, int k) {
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;
        int count = countSubarrays(arr, mid);
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
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int k;
    cout << "Enter the number of subarrays : ";
    cin >> k;

    int sum = largetSum(arr, k);
    cout << "The largest subarray sum is : " << sum << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where M = sum - max + 1 where sum is the sum of all
 * elements of the array and max is the maximum element in the array. We are applying
 * Binary Search and for every iteration, we are finding the sum
 * 
 * Space Complexity : O(1) since we are not using any extra space
 */