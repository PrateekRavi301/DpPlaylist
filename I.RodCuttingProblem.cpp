#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=4;
//	cin>>n>>w;
	int length[n]={1,2,3,4}; //Sol: 2,2 , max profit: 4+4=8
	int price[n]={1,4,5,7};
//	for(int i=0;i<n;i++)cin>>wt[i];
//	for(int i=0;i<n;i++)cin>>price[i];
	
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(length[i-1]<=j){
				 dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
			}else if(length[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[n][n];
	return 0;
}
