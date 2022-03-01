#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=4,w=7;
//	cin>>n>>w;
	int wt[n]={1,3,4,5};
	int price[n]={1,4,5,7};
//	for(int i=0;i<n;i++)cin>>wt[i];
//	for(int i=0;i<n;i++)cin>>price[i];
	
	int dp[n+1][w+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(wt[i-1]<=j){
				 dp[i][j] = max(price[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}else if(wt[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][w];
	return 0;
}
