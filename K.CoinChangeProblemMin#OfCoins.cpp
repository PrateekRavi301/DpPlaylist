#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=3;
//	cin>>n>>w;
	int coin[n]={1,2,3}; //Sol: 2+3 , min coins: 2
	int sum=5;
//	for(int i=0;i<n;i++)cin>>wt[i];
//	for(int i=0;i<n;i++)cin>>price[i];
	
	int dp[n+1][sum+1];
		for(int j=0;j<sum+1;j++){
			dp[0][j]=INT_MAX-1;  //i=0,j=0; coin[]={} and sum=0, here infinite coins are required, that is why we insert Max-1;
		}

		for(int i=1;i<n+1;i++){
			dp[i][0] = 0;
		}
		
		for(int j=1;j<sum+1;j++){  // Initializing 2nd row manually
			if(j%coin[0]==0){
				dp[1][j] = j/coin[0]; 
			}
		}
	for(int i=2;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(coin[i-1]<=j){
				 dp[i][j] = min(1+dp[i][j-coin[i-1]] , dp[i-1][j]);
			}else if(coin[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[n][sum];
	return 0;
}
