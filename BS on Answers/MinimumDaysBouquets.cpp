/**
 * You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  
 * denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
 * You can only pick already bloomed roses that are adjacent to make a bouquet. 
 * You are also told that you require exactly 'k' adjacent bloomed roses to make a 
 * single bouquet.
 * Find the minimum number of days required to make at least ‘m' bouquets each 
 * containing 'k' roses. Return -1 if it is not possible.
 * 
 * Example 1:
 * Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
 * Result: 12
 * Explanation: On the 12th the first 4 flowers and the last 3 flowers would have 
 * already bloomed. So, we can easily make 2 bouquets, one with the first 3 and 
 * another with the last 3 flowers.
 * 
 * Example 2:
 * Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
 * Result: -1
 * Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 
 * 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.
 */

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& arr, int day, int m, int k) {
    int n = arr.size();
    int cnt = 0; //To count consecutives
    int noOfB = 0; //To count total number of bouquets

    for(int i=0;i<n;i++) {
        if(arr[i] <= day) {
            cnt++;
        } else {
            noOfB += cnt/k;
            cnt = 0;
        }
    }
    noOfB += cnt/k; 
    return (noOfB >= m);
}

int roseGarden(vector<int>& arr, int k, int m) {
    long long val = m * 1LL * k * 1LL;
    //Impossible case
    int n = arr.size();
    if(val > n) return -1;
    int maxi = INT_MIN; //To store the maximum in the given array
    int mini = INT_MAX; //To store the minimum in the given array
    //Finding the minimum and maximum in the array
    for(int i=0;i<n;i++) {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    //Applying Binary Search
    int low = mini, high = maxi;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(possible(arr, mid, m, k)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of roses : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the bloom days : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int m, k;
    cout << "Enter the number of bouquets : ";
    cin >> m;
    cout << "Enter the number of consecutive roses : ";
    cin >> k;

    int miniDay = roseGarden(arr, k, m);

    if(miniDay == -1) 
        cout << "We cannot make " << m << " bouquets.\n" << endl;
    else
        cout << "We can make the bouquets on day " << miniDay << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log D) where N is the size of the array and D is the range 
 * between the minimum and the maximum element in the array
 * 
 * Space Complexity : O(1) since we are not using any extra data structure
 */