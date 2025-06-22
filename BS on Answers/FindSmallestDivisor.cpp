/**
 * You are given an array of integers 'arr' and an integer i.e. a threshold value 
 * 'limit'. Your task is to find the smallest positive integer divisor, such that 
 * upon dividing all the elements of the given array by it, the sum of the division's 
 * result is less than or equal to the given threshold value.
 * 
 * Example 1:
 * Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
 * Result: 3
 * Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
 * The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all 
 * the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is 
 * equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.
 * 
 * Example 2:
 * Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
 * Result: 2
 * Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 
 * 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.
 */

#include <bits/stdc++.h>
using namespace std;

int sumOfD(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0; //To store the sum of all divisions
    for(int i=0;i<n;i++) {
        sum += ceil((double)arr[i]/(double)k);
    }
    return sum;
}

int findDivisor(vector<int>& arr, int limit) {
    int n = arr.size(); //size of the array
    if(n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Applying Binary Search
    while(low <= high) {
        int mid = (low + high) / 2;
        if(sumOfD(arr, mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the numbers : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int limit;
    cout << "Enter the threshold : ";
    cin >> limit;

    int div = findDivisor(arr, limit);

    cout << "The smallest divisor is : " << div << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where N = size of the array and M is the maximum
 * element in the array.
 * Reason : We are applying Binary Search from the range [1...M] and for every 
 * element we are traversing the entire array to find the sum of divisions
 * 
 * Space Complexity: O(1)
 * Reason: We are not using any extra data structure
 */