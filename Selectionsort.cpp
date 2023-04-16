#include<iostream>
using namespace std;

int main()
{
	int a[]={23,4,1,22,10,5,11,19};
	int n=8,min;
	
	for(int i=0; i<n-1; i++)
	{
		min =i;
		for(int j=i+1; j<n; j++)
		{
			if(a[min] > a[j])
				min=j;
		}
			
			int temp =a[i];
			a[i] = a[min];
			a[min]=temp;
	}
	
	cout<<"Sorted array"<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}