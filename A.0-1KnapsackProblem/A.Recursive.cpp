#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;

int knapsack(int wt[], int price[], int w, int n){
	if(w==0 || n==0){
		return 0;
	}
	
	if(wt[n-1]<=w){
		return max(price[n-1]+knapsack(wt,price,w-wt[n-1],n-1),
					knapsack(wt,price,w,n-1));
	}else if(wt[n-1]>w){
		return knapsack(wt,price,w,n-1);
	}
}

int main()
{
	int n=4,w=7;
//	cin>>n>>w;
	int wt[n]={1,3,4,5};
	int price[n]={1,4,5,7};
//	for(int i=0;i<n;i++)cin>>wt[i];
//	for(int i=0;i<n;i++)cin>>price[i];
	
	int ans = knapsack(wt,price,w,n);
	
	cout<<ans;
	return 0;
}
