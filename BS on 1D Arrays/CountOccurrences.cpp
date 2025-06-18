/**
 * You are given a sorted array containing N integers and a number X, you have 
 * to find the occurrences of X in the given array.
 * 
 * Example 1:
 * Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
 * Output: 4
 * Explanation: 3 is occurring 4 times in the given array so it is our answer.
 * 
 * Example 2:
 * Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
 * Output: 5
 * Explanation: 2 is occurring 5 times in the given array so it is our answer.
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

    int count = ans.second - ans.first + 1;
    cout << "The count is : " << count << endl;

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

