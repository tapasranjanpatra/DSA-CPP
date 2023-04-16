#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x) {
   
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sorted array elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> x;
    int result = binary_search(arr, n, x);
    if(result == -1) {
        cout << "Element not found in the array\n";
    } else {
        cout << "Element found at index: " << result << "\n";
    }
    return 0;
}
