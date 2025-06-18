/**
 * Given a sorted array of N integers, write a program to find the index of 
 * the first and last occurrence of the target key. If the target is not found 
 * then return -1 -1.
 * 
 * Note: Consider 0 based indexing
 * 
 * Example 1:
 * Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
 * Output: 2 4
 * Explanation: As the target value is 13 , it appears for the first time 
 * at index number 2 and for the last time at index number 4.
 * 
 * Example 2:
 * Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
 * Output: -1 -1
 * Explanation: Target value 60 is not present in the array. 
 */

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    int first = -1; //To keep the index of first occurrence

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            first = mid;
            high = mid - 1;
        } else if(arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int>& arr, int n, int k) {
    int low = 0;
    int high = n - 1;
    int last = -1; //To keep the index of the first occurence

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            last = mid;
            low = mid + 1;
        } else if(arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return last;
}

pair<int,int> FirstAndLastOccurrences(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if(first == -1) return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
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

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    pair<int, int> ans = FirstAndLastOccurrences(arr, n, k);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}

/**
 * Time Complexity - 2 * O(log N) where N = size of the array (base is 2)
 * Reason - We are applying Binary Search Algorithm twice, each for finding
 * first and last occurrence. One run takes O(log N) time. So, the overall
 * complexity is 2 * O(log N). However, if there is no occurrence, the first
 * occurrence part will only run and hence the complexity will boil down to
 * O(log N)
 * 
 * Space Complexity - O(1) since we are not using any extra space.
 */