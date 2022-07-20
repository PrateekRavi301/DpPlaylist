#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int i,int j,int dp[][101] ){
	int ans=INT_MAX;
	if(i>=j)return 0;
	if(dp[i][j]!=0)return dp[i][j];
	for(int k=i;k<j;k++){
		int temp = solve(nums,i,k,dp)+solve(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j];
		ans = min(ans,temp);
	}
	return dp[i][j]=ans;
}

int main()
{
	vector<int> nums = {40,20,30,10,30};
	int dp[101][101];
	memset(dp,-1,sizeof(dp));
	int n=nums.size();
	cout<<solve(nums,1,n-1,dp);
    return 0;
}
