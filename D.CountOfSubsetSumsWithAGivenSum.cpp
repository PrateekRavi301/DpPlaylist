#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=5,sum=10;
//	cin>>n>>sum;
	int a[n] = {2,3,7,8,10};
//	for(int i=0;i<n;i++)cin>>a[i];

	int dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)dp[i][j]=0;
			if(j==0)dp[i][j]=1;
		}
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(a[i-1]<=j){
				 dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j] ;
			}else if(a[i-1]>j){
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
