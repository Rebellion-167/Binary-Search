/**
 * Given two sorted arrays arr1 and arr2 of size m and n respectively, return the 
 * median of the two sorted arrays. The median is defined as the middle value of a 
 * sorted list of numbers. In case the length of the list is even, the median is the 
 * average of the two middle elements.
 * 
 * Example 1:
 * Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
 * Result: 3.5
 * Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. 
 * As the length of the merged list is even, the median is the average of the two 
 * middle elements. Here two medians are 3 and 4. So the median will be the average 
 * of 3 and 4, which is 3.5.
 * 
 * Example 2:
 * Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
 * Result: 3
 * Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. 
 * The median is simply 3.
 */

#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();
    //if n1 is bigger, swapping the arrays:
    if(n1 > n2) return findMedian(b, a);
    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    int low = 0, high = n1;

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
            if(n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminating the halves:
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main() {
    int n1, n2;
    cout << "Enter the size of the first array : ";
    cin >> n1;
    cout << "Enter the size of the second array : ";
    cin >> n2;

    vector<int> a;
    vector<int> b;

    cout << "Enter the elements in the first array : ";
    for(int i=0;i<n1;i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cout << "Enter the elements in the second array : ";
    for(int i=0;i<n2;i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    double median = findMedian(a, b);

    cout << "The median is : " << median <<endl;

    return 0;
}

/**
 * Time Complexity : O(log(min(n1, n2))) where n1 and n2 are the sizes of the two arrays
 * Reason : We are applying Binary Search algorithm on the range [0, min(n1, n2)]
 * 
 * Space Complexity : O(1) as no extra space is used
 */