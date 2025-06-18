/**
 * Given an integer array arr of size N, sorted in ascending order (with distinct 
 * values) and a target value k. Now the array is rotated at some pivot point unknown 
 * to you. Find the index at which k is present and if k is not present return -1.
 * 
 * Example 1:
 * Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
 * Result: 4
 * Explanation: Here, the target is 0. We can see that 0 is present in the given 
 * rotated sorted array, nums. Thus, we get output as 4, which is the index at which 
 * 0 is present in the array.
 * 
 * Example 2:
 * Input Format: arr = [4,5,6,7,0,1,2], k = 3
 * Result: -1
 * Explanation: Here, the target is 3. Since 3 is not present in the given rotated 
 * sorted array. Thus, we get the output as -1.
 */

#include <bits/stdc++.h>
using namespace std;

int searchReverseSorted(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            return mid;
        }
        //Checking which half is sorted
        //left sorted
        else if(arr[low] <= arr[mid]) {
            //Does element lie in left sorted half?
            if(arr[low] <= k && k <= arr[mid])
            //If yes, fine, moving to the left half and
            //eliminating the right 
                high = mid - 1;
            else
            //Moving to right half since element is 
            //not in left half  
                low = mid + 1; 
        }
        //right sorted
        else {
            //Does element lie in right sorted half?
            if(arr[mid] <= k && k <= arr[high])
            //If yes, fine, moving to the right half and
            //eliminating the left half
                low = mid + 1;
            else
            //Moving to the left half since element is
            //not in right half    
                high = mid - 1;
        }
    }
    return -1; //Element not found
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

    int ind = searchReverseSorted(arr, n, k);

    if(ind != -1)
        cout << "Element present at index " << ind << endl;
    else
        cout << "Element not present" << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array (base is 2)
 * Reason : We are just using the Binary Search Algorithm and adding small 
 * unit level operations according to our neccessities. Hence it will follow the 
 * same complexity as the Binary Search Algorithm, which is O(log N)
 * 
 * Space Complexity : O(1) since we are not using any extra space
 */