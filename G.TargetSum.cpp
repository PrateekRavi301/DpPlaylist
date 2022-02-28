#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=4,targetsum=1,range=0;                               //  subsets are: 1,3   1,2
//	cin>>n>>targetsum;															1,3   1,2
	int a[n] = {1,1,2,3};  								//					1,1,2   3			
//	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=0;i<n;i++)range+=a[i];
	
	int tsum=  (range+targetsum)/2;
	
	int dp[n+1][tsum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<tsum+1;j++){
			if(i==0)dp[i][j]=0;
			if(j==0)dp[i][j]=1;
		}
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<tsum+1;j++){
			if(a[i-1]<=j){
				 dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j] ;
			}else if(a[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	
	cout<<dp[n][tsum]<<endl;
	return 0;
}
