/**
 * You're given an sorted array arr of n integers and an integer x. 
 * Find the floor and ceiling of x in arr[0..n-1].
 * The floor of x is the largest element in the array which is smaller 
 * than or equal to x.
 * The ceiling of x is the smallest element in the array greater than or 
 * equal to x.
 * 
 * Example 1:
 * Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
 * Result: 4 7
 * Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in 
 * the array is 7.
 * 
 * Example 2:
 * Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
 * Result: 8 8
 * Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the 
 * array is also 8.
 */

#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
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

    int x;
    cout << "Enter the value of x : ";
    cin >> x;

    int floor = findFloor(arr, x);
    int ceil = findCeil(arr, x);

    cout << "The floor is : " << floor << endl;
    cout << "The ceil is : " << ceil << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of array (base is 2)
 * Space Complexity : O(1)
 */