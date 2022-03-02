#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;

//int static dp[100][100]; If we declare here , then we dont have to pass it in every function call.

int LCS(string a, string b, int n, int m,int dp[][100]){
	if(n==0 || m==0)
		return 0;
		
	if(dp[n][m]!=-1)
		return dp[n][m];
		
	if(a[n-1]==b[m-1]){
		return dp[n][m]=1+LCS(a,b,n-1,m-1,dp);
	}else{
		return dp[n][m]=max(LCS(a,b,n-1,m,dp),LCS(a,b,n,m-1,dp));
	}
}

int main()
{
	string a="abcdgh";
	string b="abedfhr";
//	cin>>a;
//	cin>>b;
	
	int n = a.length(),m=b.length();

	int dp[100][100];
	memset(dp,-1,sizeof(dp));
//	int dp[n+1][m+1]={-1};
	
	cout<<LCS(a,b,n,m,dp);
	
	return 0;
}
