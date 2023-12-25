#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum sum of Non-Adjacent Elements

// Recursive version
int findMax(int ind, vector<int> &nums)
{
	if(ind == 0)
	{
		return nums[ind];
	}

	if(ind < 0) {
		return 0;
	}

	// include the current number
	
	int pick = nums[ind] + findMax(ind-2, nums);

	int notPick = findMax(ind-1, nums);

	return max(pick, notPick);
}


// Memoized version
int findMaxM(int ind, vector<int> &nums, vector<int> &dp)
{
	if(ind == 0)
	{
		return nums[ind];
	}

	if(ind < 0)
	{
		return 0;
	}

	if(dp[ind] != -1) return dp[ind];
	
	int pick = nums[ind] + findMaxM(ind-2, nums, dp);
	int notPick = findMaxM(ind-1, nums, dp);

	return dp[ind] = max(pick, notPick);
}

// Space Optimized (Tabulated version)
int findMaxT(int ind, vector<int> &nums)
{
	int prev = nums[0], prev2 = 0, current, pick, notPick;
	for(int i=1; i<=ind; i++)
	{
		pick = nums[i];
		if(i>1)
		{
			pick += prev2;	
		}
		notPick = prev;
		current = max(pick, notPick);
		prev2 = prev;
		prev = current;
	}
	return prev;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, num;
	cin>>n;
	vector<int> nums, dp(n+1, -1);
	for(int i=0; i<n; i++)
	{
		cin>>num;
		nums.push_back(num);
	}
	cout<<findMax(n-1, nums)<<endl;
	cout<<findMaxM(n-1, nums, dp)<<endl;
	cout<<findMaxT(n-1, nums)<<endl;
}