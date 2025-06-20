/**
 * Given an array of N integers. Every number in the array except one appears 
 * twice. Find the single number in the array.
 * 
 * Example 1:
 * Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
 * Result: 4
 * Explanation: Only the number 4 appears once in the array.
 * 
 * Example 2:
 * Input Format: arr[] = {1,1,3,5,5}
 * Result: 3
 * Explanation: Only the number 3 appears once in the array.
 */

#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int>& arr) {
    int n = arr.size();
    if(n==1) return arr[0];
    //Checking for the first element
    //since it doesn't have a preceeding element
    if(arr[0] != arr[1]) return arr[0];
    //Checking for the last element
    //since it doesn't have a succeeding element
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    //Shrinking the search space and
    //starting the search from [1...n-2]
    int low = 1;
    int high = n - 2;

    while(low <= high) {
        int mid = (low + high) / 2;
        //Checking whether the mid element
        //is the single element or not
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        //Else we are checking in which half we are
        //(even, odd) -> element is in the right half
        //so eliminate left half
        //(odd, even) -> element is in the left half
        //so eliminate right half

        //We will either be on an odd or even element
        //so checking for both conditions
        else if(((mid%2==1) && arr[mid] == arr[mid - 1])
                || (mid%2==0) && arr[mid] == arr[mid + 1]) {
            //Eliminating left half
            low = mid + 1;
        } else {
            //Eliminating right half
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

    int ele = findSingleElement(arr);

    cout << "The single element is : " << ele << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array (base is 2)
 * Reason : We are using the Binary Search Algorithm with minor tweaks
 * 
 * Space Complexity: O(1)
 * Reason : We are not using any extra data structure 
 */
