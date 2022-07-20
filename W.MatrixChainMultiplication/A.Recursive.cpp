#include <bits/stdc++.h>
#include<thread>
#include<unistd.h>
using namespace std;

int solve(vector<int>& nums,int i,int j){
	int ans=INT_MAX;
	if(i>=j)return 0;
	for(int k=i;k<j;k++){
		int temp = solve(nums,i,k)+solve(nums,k+1,j)+nums[i-1]*nums[k]*nums[j];
		ans = min(ans,temp);
	}
	return ans;
}

int main()
{
	vector<int> nums = {40,20,30,10,30};
	int n=nums.size();
	cout<<solve(nums,1,n-1);


    return 0;
}
