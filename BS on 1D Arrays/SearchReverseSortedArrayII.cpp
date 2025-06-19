/**
 * Given an integer array arr of size N, sorted in ascending order (may contain 
 * duplicate values) and a target value k. Now the array is rotated at some pivot 
 * point unknown to you. Return True if k is present and otherwise, return False. 
 * 
 * Example 1:
 * Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
 * Result: True
 * Explanation: The element 3 is present in the array. So, the answer is True.
 * 
 * Example 2:
 * Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
 * Result: False
 * Explanation: The element 10 is not present in the array. So, the answer is False.
 */

#include <bits/stdc++.h>
using namespace std;

bool searchArray(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) return true;
        //If elements at low, mid and high are same, we are
        //shrinking the search space from both ends
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }
        //Checking which half is sorted
        //Is it left sorted?
        else if(arr[low] < arr[mid]) {
            //If yes, then does the element lie in left half?
            if(arr[low] <= k && k <= arr[mid]) {
                //Triming down the right half
                high = mid - 1;
            } else {
                //Triming down the left half
                low = mid + 1;
            }
        } 
        //If not left sorted, then it will definitely be right sorted
        else {
            //Does element lie in right half
            if(arr[mid] <= k && k <= arr[high]) {
                //Triming down the left half
                low = mid + 1;
            } else {
                //Triming down the right half
                high = mid - 1;
            }
        }
    }
    return false; //If element is not found
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
    cout << "Enter the value of k : ";
    cin >> k;

    bool ans = searchArray(arr, n, k);

    cout << boolalpha << ans << endl;

    return 0;
}

/**
 * Time Complexity - O(log N) for best and average case
 *                   O(N/2) for worst case. N = size of the array
 * Reason : In the best and average cases, the binary search algorithm is 
 * primarily utilized and hence the time complexity is O(log N). However, in the 
 * worst case, where all the elements are same but not the target, we are reducing
 * the search space by adjusting the low and the high until they intersect. This
 * worst case complexity hence becomes O(N/2).
 * 
 * Space Complexity - O(1) since we are not using any extra data structure.
 */