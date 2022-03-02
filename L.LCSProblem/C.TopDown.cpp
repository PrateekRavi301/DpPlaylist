#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;

//int static dp[100][100]; If we declare here , then we dont have to pass it in every function call.

int LCS(string a, string b, int n, int m,int dp[][100]){
	for(int i=0;i<n+1;i++){       //	Initalization OR Base case : if(n==0 || m==0)return 0;
		dp[i][0]=0;
	}
	for(int j=0;j<m+1;j++){
		dp[0][j]=0;
	}	
	
	for(int i=1;i<n+1;i++){      									
		for(int j=1;j<m+1;j++){
			if(a[i-1]==b[j-1]){							//Recusrive Algo OR Choice Diagram			
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}	
	return dp[n][m];
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
