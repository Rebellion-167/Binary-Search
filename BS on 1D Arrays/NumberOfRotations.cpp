/**
 * Given an integer array arr of size N, sorted in ascending order (with distinct 
 * values). Now the array is rotated between 1 to N times which is unknown. Find 
 * how many times the array has been rotated. 
 * 
 * Example 1:
 * Input Format: arr = [4,5,6,7,0,1,2,3]
 * Result: 4
 * Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice 
 * that the array has been rotated 4 times.
 * 
 * Example 2:
 * Input Format: arr = [3,4,5,1,2]
 * Result: 3
 * Explanation: The original array should be [1,2,3,4,5]. So, we can notice that 
 * the array has been rotated 3 times.
 */

#include <bits/stdc++.h>
using namespace std;

int findRotations(vector<int>& arr) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        //If the search space is already sorted
        //then the minimum element will be the leftmost
        if(arr[low] <= arr[high]) {
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
                break;
            }
        }
        //Else we are checking which half is sorted
        //Is it left sorted?
        else if(arr[low] <= arr[mid]) {
            //Picking the minimum from the left half
            //and eliminating the half
            //Here, minimum is leftmost element
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        //Else it will definitely be right sorted
        else {
            //Picking the minimum from the right half 
            //and eliminating the right half
            //Here, the minimum is the middle element
            if(arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
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

    int ind = findRotations(arr);

    cout << "The number of rotations are : " << ind << endl;

    return 0;
}

/**
 * Time Complexity - O(log N) where N = size of the array
 * Reason - We are using the Binary Search Algorithm.
 * 
 * Space Complexity - O(1)
 * Reason - We are not using any extra space
 */