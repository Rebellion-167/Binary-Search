/**
 * Given two numbers N and M, find the Nth root of M. The nth root of a number 
 * M is defined as a number X when raised to the power N equals M. If the 'nth 
 * root is not an integer, return -1.
 * 
 * Example 1:
 * Input Format: N = 3, M = 27
 * Result: 3
 * Explanation: The cube root of 27 is equal to 3.
 * 
 * Example 2:
 * Input Format: N = 4, M = 69
 * Result: -1
 * Explanation: The 4th root of 69 does not exist. So, the answer is -1.
 */

#include <bits/stdc++.h>
using namespace std;

//return 1 if == m
//return 0 if < m
//return 2 if > m
int func(int mid, int n, int m) {
    long long ans = 1;
    for(int i=1;i<=n;i++) {
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    else return 0;
}

int findRoot(int m, int n) {
    int low = 1;
    int high = m;

    while(low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if(midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1; //If there is no root
}

int main() {
    int m;
    cout << "Enter the number : ";
    cin >> m;

    int n;
    cout << "Enter Root : ";
    cin >> n;

    int root = findRoot(m, n);

    cout << root << endl;

    return 0;
}

/**
 * Time Complexity : O(log M * log N) where M and N are the number and root
 * respectively.
 * Reason : We are using Binary Search Algorithm which uses O(log M) time. Also, to 
 * find the root, we are using Binary Exponentiation which uses O(log N) time.
 * 
 * Space Complexity: O(1)
 * Reason : We are not using any extra data structure
 */