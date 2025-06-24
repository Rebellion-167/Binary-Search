/**
 * You are given an array 'arr' of size 'n' which denotes the position of stalls.
 * You are also given an integer 'k' which denotes the number of aggressive cows.
 * You are given the task of assigning stalls to 'k' cows such that the minimum 
 * distance between any two of them is the maximum possible.
 * Find the maximum possible minimum distance.
 * 
 * Example 1:
 * Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
 * Result: 3
 * Explanation: The maximum possible minimum distance between any two cows will be 
 * 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between 
 * cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater 
 * than 3 in any ways.
 * 
 * Example 2:
 * Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
 * Result: 5
 * Explanation: The maximum possible minimum distance between any two cows will be 
 * 5 when 2 cows are placed at positions {1, 6}. 
 */

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>& arr, int dist, int cows) {
    int cntCows = 1; //Keeping the count of cows we are placing
    int last = arr[0]; //The last index where we have placed our cow
    int n = arr.size();

    for(int i=1;i<n;i++) {
        //If the distance between consecutive cows is greater
        //than the given distance, we are placing a cow
        if(arr[i] - last >= dist) {
            cntCows++;
            last = arr[i];
        } 
        if(cntCows >= cows) return true;
    }
    return false;
}

int placeCows(vector<int>& arr, int cows) {
    //Sorting the array to make consecutive stalls
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 1;
    int high = arr[n-1] - arr[0];

    while(low <= high) {
        int mid = (low + high) / 2;
        //If we can place our cows with the given distance
        //it might be our answer and we are maximizing
        if(canWePlace(arr, mid, cows) == true)
            low = mid + 1;
        else    
            high = mid - 1;
    }
    return high;
}

int main() {
    int n;
    cout << "Enter the number of stalls : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the position of stalls : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int cows;
    cout << "Enter the number of cows : ";
    cin >> cows;

    int minDist = placeCows(arr, cows);

    cout << "The minimum distance between cows : " << minDist << endl;

    return 0;
}

/**
 * Time Complexity : O(N*log N) + O(N*log M) where M = max - min
 * Reason: We are sorting the given array which takes O(N*log N) time complexity. Then
 * we are applying the Binary Search Algorithm and for every iteration, we are finding
 * whether we can place the given number of cows.
 * 
 * Space Complexity : O(1)
 * Reason : We are not using any extra data structure
 */
