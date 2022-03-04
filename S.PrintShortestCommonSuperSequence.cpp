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
string printSCS(string a, string b, int n, int m, int dp[][100]){
	string ans="";
	int i=n,j=m;
	while(i!=0 || j!=0){
		if(a[i-1]==b[j-1]){
			ans = a[i-1] + ans;
			i--;
			j--;
		}else{
			if(dp[i-1][j]>dp[i][j-1]){
				ans = a[i-1]+ans;
				i--;
			}else{
				ans  = b[j-1]+ans;
				j--;
			}
		}
	}
	//Now, either i=0 or j=0, so only one loop from below will run
	// Why? Bcz, if A:"ab" and B is empty , then SCS is "ab" but LCS is empty. That is why we have to include these 2 loops here.
	while(i!=0){
		ans = a[i-1] + ans;
			i--;
	}
	while(j!=0){
		ans  = b[j-1]+ans;
				j--;
	}
	return ans;
}

int main()
{
	string a="abcdaf";		
	string b = "acbcf" ;  
	
//	cin>>a;
//	cin>>b;
	
	int n = a.length(),m=b.length();

	int dp[100][100];
	memset(dp,-1,sizeof(dp));
//	int dp[n+1][m+1]={-1};
	
	int ans = LCS(a,b,n,m,dp);      // Find common letters from LCS fn
	
	for(int i=0;i<n+1;i++){      									
		for(int j=0;j<m+1;j++){
			cout<<dp[i][j];
		}
		cout<<endl;
	}
	
	string res = printSCS(a,b,n,m,dp);
	cout<<res <<endl;  // answer =  Shortest Common SuperSequence
	

	
	return 0;
}
