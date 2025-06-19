/**
 * Given an integer array arr of size N, sorted in ascending order (with distinct 
 * values). Now the array is rotated between 1 to N times which is unknown. Find 
 * the minimum element in the array. 
 * 
 * Example 1:
 * Input Format: arr = [4,5,6,7,0,1,2,3]
 * Result: 0
 * Explanation: Here, the element 0 is the minimum element in the array.
 * 
 * Example 2:
 * Input Format: arr = [3,4,5,1,2]
 * Result: 1
 * Explanation: Here, the element 1 is the minimum element in the array.
 */

#include <bits/stdc++.h>
using namespace std;

int findMinimum(vector<int>& arr, int n) {
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;
        //If the search space is already sorted
        //then arr[low] will be the final minimum
        //and thus breaking out
        if(arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        //Else if it is only left sorted
        else if(arr[low] <= arr[mid]) {
            //Pick out the minimum from the sorted part
            //and eliminate the whole part
            //Here, the minimum will be the leftmost element i.e., arr[low]
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        //Else it will definitely be right sorted
        else {
            //Pick out the minimum from the sorted part
            //and eliminate the whole part
            //Here, the minimum will be the middle element i.e., arr[mid]
            ans = min(ans, arr[mid]);
            high = mid - 1;
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

    int mini = findMinimum(arr, n);

    cout << "The minimum is : " << mini << endl;

    return 0;
}

/**
 * Time Complexity - O(log N) where N = size of the array
 * Space Complexity - O(1)
 */