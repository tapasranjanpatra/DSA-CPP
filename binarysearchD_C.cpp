#include <iostream>
#include <vector>

using namespace std;

// Binary search function using divide-and-conquer technique
int binarySearch(vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1; // element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid; // element found
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target); // search in left half
    } else {
        return binarySearch(arr, mid + 1, right, target); // search in right half
    }
}

int main() {
    // Input vector and target element from user
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search for: ";
    cin >> target;
    
    // Search for target element using binary search
    int result = binarySearch(arr, 0, arr.size() - 1, target);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}
