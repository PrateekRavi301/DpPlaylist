#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pp ;

int LCS(string a, string b, int n, int m){
	if(n==0 || m==0)
		return 0;
		
	if(a[n-1]==b[m-1]){
		return 1+LCS(a,b,n-1,m-1);
	}else{
		return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
	}
}

int main()
{
	string a="abcdgh";
	string b="abedfhr";
//	cin>>a;
//	cin>>b;
	
	int n = a.length(),m=b.length();

	
	cout<<LCS(a,b,n,m);
	
	return 0;
}
