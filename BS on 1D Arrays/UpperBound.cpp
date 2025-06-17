/**
 * Given a sorted array of N integers and an integer x, write a program to 
 * find the upper bound of x.
 * 
 * Example 1:
 * Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
 * Result: 3
 * Explanation: Index 3 is the smallest index such that arr[3] > x.
 * 
 * Example 2:
 * Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
 * Result: 4
 * Explanation: Index 4 is the smallest index such that arr[4] > x.
 */

#include <bits/stdc++.h>
using namespace std;

int findUpperBound(vector<int>& arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > x) {
            ans = mid;
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

    int ind = findUpperBound(arr, n, x);

    cout << "The upper bound is : " << ind << endl;

    return 0;
}