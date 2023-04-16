#include <iostream>
using namespace std;

int fibSearch(int arr[], int n, int x) {
    int fib2 = 0;  // (m-2)'th Fibonacci number
    int fib1 = 1;  // (m-1)'th Fibonacci number
    int fib = fib2 + fib1; // m'th Fibonacci number

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset+fib2, n-1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 && arr[offset+1] == x) {
        return offset+1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the value to search: ";
    cin >> x;

    int index = fibSearch(arr, n, x);

    if (index == -1) {
        cout << "Element not found";
    }
    else {
        cout << "Element found at index " << index;
    }

    return 0;
}
