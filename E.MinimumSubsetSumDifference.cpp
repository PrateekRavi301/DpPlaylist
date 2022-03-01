#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=3,range=0;
//	cin>>n;
	int a[n] = {1,2,7};  // S1={1,2} S2={7} diff = 4
//	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=0;i<n;i++)range+=a[i];
	bool dp[n+1][range+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<range+1;j++){
			if(i==0)dp[i][j]=false;
			if(j==0)dp[i][j]=true;
		}
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<range+1;j++){
			if(a[i-1]<=j){
				 dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;
			}else if(a[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<range+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	vector<int> ans;
	
	for(int j=0;j<=range/2;j++){
		if(dp[n][j])ans.push_back(j);
	}
	
	int mn = INT_MAX;
	for(auto x:ans){
		if(range - 2*x < mn){
			mn = range - 2*x;
		}
	}
	cout<<mn<<endl;
	return 0;
}
