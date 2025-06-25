/**
 * Given two sorted arrays of size m and n respectively, you are tasked with finding 
 * the element that would be at the kth position of the final sorted array.
 * 
 * Examples :
 * 
 * Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
 * Output: 6
 * Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10].
 * The 5th element of this array is 6.
 * 
 * Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], 
 * k = 7
 * Output: 256
 * Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 
 * 445, 770, 892]. The 7th element of this array is 256.
 */

#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size();
    int n2 = b.size();
    //If n1 is bigger, swapping the arrays:
    if(n1 > n2) return findKthElement(b, a, k);
    int left = k; //length of left half

    //Applying Binary Search:
    int low = max(0, k - n2), high = min(k, n1);
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        //Calculating l1, l2, r1, r2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        //Eliminating the halves:
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main() {
    int n1;
    cout << "Enter the size of the first array : ";
    cin >> n1;
    vector<int> a;
    cout << "Enter the elements in the first array : ";
    for(int i=0;i<n1;i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    int n2;
    cout << "Enter the size of the second array : ";
    cin >> n2;
    vector<int> b;
    cout << "Enter the elements in the second array : ";
    for(int i=0;i<n2;i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    int ele = findKthElement(a, b, k);

    cout << "The element in kth position of the combined sorted array is : " << ele << endl;

    return 0;
}

/**
 * Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
 * Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. 
 * The range length <= min(m, n).
 * 
 * Space Complexity: O(1), as we are not using any extra space to solve this problem.
 */