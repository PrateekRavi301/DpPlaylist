#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;


int knapsack(int wt[], int price[], int w, int n,int dp[][100]){
	if(w==0 || n==0){
		return 0;
	}
	
	if(dp[n][w]!=-1){
		return dp[n][w];
	}
	
	if(wt[n-1]<=w){
		return dp[n][w] = max(price[n-1]+knapsack(wt,price,w-wt[n-1],n-1,dp),
					knapsack(wt,price,w,n-1,dp));
	}else if(wt[n-1]>w){
		return dp[n][w] = knapsack(wt,price,w,n-1,dp);
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
	
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int ans = knapsack(wt,price,w,n,dp);
	
	cout<<ans;
	return 0;
}
