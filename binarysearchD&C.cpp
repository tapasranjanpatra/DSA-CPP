#include<iostream>//BinaryS
using namespace std;
int binarySearch(int arr[], int l, int r, int x){
if (r >= l) {
	int mid = l + (r - l) / 2;
	if (arr[mid] == x)
	return mid;
 if (arr[mid] > x)
 return binarySearch(arr, l, mid - 1, x);
 return binarySearch(arr, mid + 1, r, x);
}
return -1;
}
int main(){
	int y;
	cout<<"Enter Array Index Size-:";
	cin>>y;
	int arr[y] ;
	cout<<"Enter Array Value in
	assending/decending-:";
for(int i=0;i<y;i++){
 cin>>arr[i];
}
int n = sizeof(arr) / sizeof(arr[0]);
int x ;
cout<<"enter searching array-:";
cin>>x;
int result = binarySearch(arr, 0, n - 1, x);
(result == -1)
 ? printf("Element is not present in array")
 : printf("Element is present at index %d", result);
return 0;
}