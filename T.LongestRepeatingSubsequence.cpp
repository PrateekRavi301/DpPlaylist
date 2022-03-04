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
	
	for(int i=1;i<n+1;i++){      								//Recusrive Algo OR Choice Diagram	
		for(int j=1;j<m+1;j++){
			if(a[i-1]==b[j-1] && i!=j){										//i!=j bcz, we are not taking same indexed letter into ans
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
	string a="abcabddf";		
//	Longest Repeating Subsequence: abd 
	
//	cin>>a;
//	cin>>b;
	
	int n = a.length(),m=a.length();

	int dp[100][100];
	memset(dp,-1,sizeof(dp));
//	int dp[n+1][m+1]={-1};
	
	int ans = LCS(a,a,n,m,dp);      // Find common letters from LCS fn
	
	for(int i=0;i<n+1;i++){      									
		for(int j=0;j<m+1;j++){
			cout<<dp[i][j];
		}
		cout<<endl;
	}
	
	
	cout<<"Length of Longest Repeating Subsequence: "<<ans <<endl;  
	

	
	return 0;
}
