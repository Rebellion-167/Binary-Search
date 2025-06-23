/**
 * You are the owner of a Shipment company. You use conveyor belts to ship packages 
 * from one port to another. The packages must be shipped within 'd' days.
 * The weights of the packages are given in an array 'of weights'. The packages are 
 * loaded on the conveyor belts every day in the same order as they appear in the 
 * array. The loaded weights must not exceed the maximum weight capacity of the ship.
 * Find out the least-weight capacity so that you can ship all the packages 
 * within 'd' days.
 * 
 * Example 1:
 * Input Format: N = 5, weights[] = {5,4,5,2,3,4,5,6}, d = 5
 * Result: 9
 * Explanation: If the ship capacity is 9, the shipment will be done in the 
 * following manner:
 * Day         Weights            Total
 * 1        -       5, 4          -        9
 * 2        -       5, 2          -        7
 * 3        -       3, 4          -        7
 * 4        -       5              -        5
 * 5        -       6              -        6
 * So, the least capacity should be 9.
 * 
 * Example 2:
 * Input Format: N = 10, weights[] = {1,2,3,4,5,6,7,8,9,10}, d = 1
 * Result: 55
 * Explanation: We have to ship all the goods in a single day. So, the weight 
 * capacity should be the summation of all the weights i.e. 55.
 */

#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int>& arr, int cap) {
    int n = arr.size();
    int days = 1, load = 0;
    for(int i=0;i<n;i++) {
        //If incoming load is within the capacity
        //adding it in the current day
        if(load + arr[i] <= cap) {
            load += arr[i];
        } else {
            //Adding it in the next day
            days++;
            load = arr[i];
        }
    }
    return days;
}

int minimumCap(vector<int>& arr, int days) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;
        int daysReq = findDays(arr, mid);
        //If days required with the current cap is less than the
        //days allocated, we might have an answer and we are
        //looking for the least
        if(daysReq <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of containers : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the weights of each container : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int days;
    cout << "Enter number of days : ";
    cin >> days;

    int minCap = minimumCap(arr, days);

    cout << "The minimum capacity of the ship should be : " << minCap << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where M = sum - max + 1, sum is the summation of all
 * weights of the container and max is the maximum weight of the containers. 
 * Reason : We are applying Binary Search Algorithm on this range and for every day, 
 * we are calling a function that iterates through the entire array of size N.
 * 
 * Space Complexity: O(1)
 * Reason : We are not using any extra data structure
 */