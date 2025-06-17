/**
 * You are given a sorted array of integers and a target, your task is to search 
 * for the target in the given array. Assume the given array does not contain 
 * any duplicate numbers.
 * 
 * Let’s say the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.
 */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int n, int target) {
    int low = 0;
    int high = n-1;

    //Performing the steps of Binary Search:
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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

    int ind = binarySearch(arr, n, target);

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