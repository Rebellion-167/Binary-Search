/**
 * A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas.
 * An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas 
 * to be eaten.
 * Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. 
 * If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas 
 * and won’t eat any more bananas in that hour.
 * Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all 
 * the bananas within ‘h’ hours.
 * 
 * Example 1:
 * Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
 * Result: 5
 * Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat 
 * the piles accordingly. So, he will take 8 hours to complete all the piles.  
 * 
 * Example 2:
 * Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
 * Result: 25
 * Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat 
 * the piles accordingly. So, he will take 5 hours to complete all the piles.
 */

#include <bits/stdc++.h>
using namespace std;

//To find the max element in the array
int findMax(vector<int>& arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

//To calculate total number of hours required
//for a given rate k
int calculateTotalHours(vector<int>& arr, int k) {
    int total = 0;
    int n = arr.size();
    for(int i=0;i<n;i++) {
        total += ceil((double)arr[i]/(double)k);
    }
    return total;
}

//Function to find the minimum k
int findMinimumK(vector<int>& arr, int h) {
    int low = 1;
    int high = findMax(arr);
    
    while(low <= high) {
        int mid = (low + high) / 2;
        //Calculate the hours required for the current mid
        int hours = calculateTotalHours(arr, mid);
        //If that hours is less than the alloted hours
        //we might have the answer and we are 
        //looking for minimum
        if(hours <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of piles : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the number of bananas in each pile : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int h;
    cout << "Enter the number of hours : ";
    cin >> h;
    
    int required = findMinimumK(arr, h);

    cout << "The number of bananas eaten per hour must be : " << required << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where N is the size of the array and M is the
 * max element in the array
 * Reason : We are applying Binary Search for the range [1...M] and for every value of
 * mid, we are traversing the entire array to find total hours
 * 
 * Space Complexity: O(1)
 * Reason : We are not using any extra data structure
 */