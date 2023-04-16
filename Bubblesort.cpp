#include<iostream>
using namespace std;

int main(){
	
	int a[]={23,4,1,22,10,5,11,19};
	int n=8, flag =0,count=0;
	
	
	for(int i=n-1; i>=0; i--)
	{
		flag=0;
		for(int j=0; j<i ; j++)
		{
			if(a[j]>a[j+1])
			{
				count++;
				flag =1;
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		
		if(flag==0)
			break;
	}
	
	cout<<"Sorted Array"<<endl;
	cout<<count<<"times";
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" "<<endl;
	}
	return 0;
}