#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x) {
   
   for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> x;
    int result = linear_search(arr, n, x);
    if(result == -1) {
        cout << "Element not found in the array\n";
    } else {
        cout << "Element found at index: " << result << "\n";
    }
    return 0;
}
