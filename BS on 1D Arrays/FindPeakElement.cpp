/**
 * Given an array of length N. Peak element is defined as the element greater \
 * than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' 
 * < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element 
 * in the array. If there are multiple peak numbers, return the index of any peak number.
 * 
 * Note: For the first element, the previous element should be considered as negative 
 * infinity as well as for the last element, the next element should be considered as 
 * negative infinity.
 * 
 * Example 1:
 * Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
 * Result: 7
 * Explanation: In this example, there is only 1 peak that is at index 7.
 * 
 * Example 2:
 * Input Format: arr[] = {1,2,1,3,5,6,4}
 * Result: 1
 * Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. 
 * We can consider any of them.
 * 
 * Example 3:
 * Input Format: arr[] = {1, 2, 3, 4, 5}
 * Result: 4
 * Explanation: In this example, there is only 1 peak that is at the index 4.
 * 
 * Example 4:
 * Input Format: arr[] = {5, 4, 3, 2, 1}
 * Result: 0
 * Explanation: In this example, there is only 1 peak that is at the index 0.
 */

#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int>& arr) {
    int n = arr.size();
    //Edge Case - If array contains only one element
    if(n==1) return 0;
    //If leftmost element is the peak element
    if(arr[0] > arr[1]) return 0;
    //If rightmost element is the peak element
    if(arr[n-1] > arr[n-2]) return n-1;

    //Now since the edge cases are settled,
    //we will shrink the search space
    int low = 1;
    int high = n - 2;
    while(low <= high) {
        int mid = (low + high) / 2;
        //If the middle element is the peak element
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        //If it's not, it must lie on an increasing or an decreasing curve
        //If it lies on an increasing curve
        else if(arr[mid] < arr[mid + 1]) {
            //The peak will always be on the right side
            //Hence moving the low pointer to right
            low = mid + 1;
        }
        //Else it will definitely lie on an decreasing curve
        //Or there are multiple peaks and the mid lies in
        //between the peaks
        else {
            //The peak will lie on the left
            //hence moving the right pointer
            high = mid - 1;
        }
    }
    return -1; //Dummy statement
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

    int ele = peakElement(arr);

    cout << "The peak element is : " << arr[ele] << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array
 * Reason : We are using the Binary Search Algorithm
 * 
 * Space Complexity : O(1)
 * Reason : We are not using any extra data structure
 */