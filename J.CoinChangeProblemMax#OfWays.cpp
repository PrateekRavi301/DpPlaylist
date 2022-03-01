#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=3;
//	cin>>n>>w;
	int coin[n]={1,2,3}; //Sol: 1+1+1+1+1; 1+1+3; 1+1+1+2; 2+2+1; 2+3 = 5 ways
	int sum=5;
//	for(int i=0;i<n;i++)cin>>wt[i];
//	for(int i=0;i<n;i++)cin>>price[i];
	
	int dp[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)dp[i][j]=0;
			if(j==0)dp[i][j]=1;
		}
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(coin[i-1]<=j){
				 dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
			}else if(coin[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[n][sum];
	return 0;
}
