#include <stdio.h>
#include<iostream>
using namespace std;
int max(int a, int b) { 
if(a>b)
return a;
else
return b;
 }   
int knapSack(int W, int wt[], int val[], int n){
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));}
int main(){
	int x;
	cout<<"Enter Item Size";
	cin>>x;
	//int profit[] = { 60, 100, 120 };
	//int weight[] = { 10, 20, 30 };
	int pro[x];
	int wei[x];
	for(int i=0;i<x;i++){
		cout<<"Profit & Weight";
		cin>>pro[i];
		cin>>wei[i];
	}
	//int W = 150;
	int w;
	cout<<"Enter Capacity-:";
	cin>>w;
	//int n = sizeof(profit) / sizeof(profit[0]);
	cout<<knapSack(w, wei, pro, x);
	return 0;}