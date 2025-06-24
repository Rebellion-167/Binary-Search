/**
 * Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages 
 * in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to 
 * allocate all the books to the students.
 * 
 * Allocate books in such a way that:
 *      Each student gets at least one book.
 *      Each book should be allocated to only one student.
 *      Book allocation should be in a contiguous manner.
 * 
 * You have to allocate the book to ‘m’ students such that the maximum number of 
 * pages assigned to a student is minimum. If the allocation of books is not possible. 
 * return -1
 * 
 * Example 1:
 * Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
 * Result: 113
 * Explanation: The allocation of books will be 12, 34, 67 | 90. One student will
 * get the first 3 books and the other will get the last one.
 * 
 * Example 2:
 * Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
 * Result: 71
 * Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
 */

#include <bits/stdc++.h>
using namespace std;

int bookPages(vector<int>& arr, int pages) {
    int students = 1; //To keep track of number of students
    long long pageStudent = 0; //To keep track of pages
    int n = arr.size();

    for(int i=0;i<n;i++) {
        if(pageStudent + arr[i] <= pages) {
            //Allocating to current student
            pageStudent += arr[i];
        } else {
            //We are allocating it to a new student
            students++;
            pageStudent = arr[i];
        }
    }
    return students;
}

int allocateBooks(vector<int>& pages, int students) {
    int n = pages.size();
    //book allocation impossible
    if(students > n) return -1;

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);

    while(low <= high) {
        int mid = (low + high) / 2;
        int page = bookPages(pages, mid);
        if(page > students) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of books : ";
    cin >> n;

    vector<int> arr;

    cout << "Enter the pages in each book : ";
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int students;
    cout << "Enter the number of students : ";
    cin >> students;

    int maxPages = allocateBooks(arr, students);

    cout << "The maximum pages that can be allocated : " << maxPages << endl;

    return 0;
}

/**
 * Time Complexity : O(N * log M) where M = (sum - max + 1) where sum is the 
 * summation of all pages of all books and max is the maximum no. of pages. We are
 * applying Binary Search Algorithm and for every iteration, we are finding whether
 * the given number of pages can be allocated
 * 
 * Space Complexity : O(1) since we are not using any extra data structure
 */