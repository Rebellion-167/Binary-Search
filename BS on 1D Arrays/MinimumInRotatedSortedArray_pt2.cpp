/**
 * Given the sorted rotated array nums that may contain duplicates, return the 
 * minimum element of this array.
 * 
 * Example 1:
 * Input: nums = [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * Input: nums = [2,2,2,0,1]
 * Output: 0
 */

#include <bits/stdc++.h>
using namespace std;

int findMinimum(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;
        ans = min(ans, arr[mid]);

        if (arr[mid] > arr[high]) {
            // Pivot is to the right
            low = mid + 1;
        } else if (arr[mid] < arr[high]) {
            // Pivot is at mid or to the left
            high = mid;
        } else {
            // arr[mid] == arr[high], can't decide; shrink
            high--;
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

    int mini = findMinimum(arr);

    cout << "The minimum is : " << mini << endl;

    return 0;
}

/**
 * Time Complexity - O(log N) on average, O(N) in the worst case due to duplicates
 * Space Complexity - O(1)
 */