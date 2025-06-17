/**
 * You are given a sorted array of integers and a target, your task is to search 
 * for the target in the given array. Assume the given array does not contain 
 * any duplicate numbers.
 * 
 * Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target) {
    //Base Case: 
    if(low > high) 
        return -1;

    int mid = (low+high)/2;

    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target) 
        return binarySearch(arr, mid+1, high, target);
    else   
        return binarySearch(arr, low, mid-1, target);
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

    int target;
    cout << "Enter the target : ";
    cin >> target;

    int ind = binarySearch(arr, 0, n-1, target);

    if(ind != -1) 
        cout << "Target is located at index " << ind << endl;
    else 
        cout << "Target not found." << endl;
    
    return 0;
}

/**
 * Time Complexity : O(log N) where N=size of the array (base is 2)
 * Space Complexity : O(1)
 */