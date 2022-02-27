#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;



int main()
{
	int n=5,sum;
//	cin>>n>>w;
	int a[n] = {2,3,7,8,10};
//	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)sum+=a[i];
	
	if(sum%2==1){
		cout<<"No";
		return 0;
	}
	sum/=2;
	bool dp[n+1][sum+1];
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i==0)dp[i][j]=false;
			if(j==0)dp[i][j]=true;
		}
	}
	
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=sum+1;j++){
			if(a[i-1]<=j){
				 dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;
			}else if(a[i-1]>j){
				 dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	if(dp[n][sum]==true)cout<<"YES";
	else cout<<"N0";
	return 0;
}
