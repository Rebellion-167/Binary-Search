/**
 * You are given a positive integer n. Your task is to find and return its square root. 
 * If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.
 * 
 * Note: The question explicitly states that if the given number, n, is not a perfect 
 * square, our objective is to find the maximum number, x, such that x squared is less 
 * than or equal to n (x*x <= n). In other words, we need to determine the floor value 
 * of the square root of n.
 * 
 * Example 1:
 * Input Format: n = 36
 * Result: 6
 * Explanation: 6 is the square root of 36.
 * 
 * Example 2:
 * Input Format: n = 28
 * Result: 5
 * Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.
 */

#include <bits/stdc++.h>
using namespace std;

int findSquareRoot(int n) {
    int low = 1;
    int high = n;
    int ans = 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        //If the current mid might be my answer
        //Storing it and looking for a larger number
        if((mid * mid) <= n) {
            ans = mid;
            low = mid + 1;
        }
        //Else cutting down the right half
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int root = findSquareRoot(n);

    cout << "The square root is : " << root << endl;

    return 0;
}

/**
 * Time Complexity : O(log N) where N = size of the array (base is 2)
 * Reason : We are using the Binary Search Algorithm
 * 
 * Space Complexity : O(1)
 * Reason : We are not using any extra data structure
 */