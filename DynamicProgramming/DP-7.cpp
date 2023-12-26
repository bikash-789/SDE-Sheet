#include <bits/stdc++.h>
using namespace std;
// Problem link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

// int uniquePaths(int m, int n) {
// 	// base case
// 	if(m==0 && n==0)
// 	{
// 		return 1;
// 	}
// 	if(m<0 || n<0)
// 	{
// 		return 0;
// 	}
// 	// recursive call
// 	int left = uniquePaths(m, n-1);
// 	int up = uniquePaths(m-1, n);

// 	return left+up;
// }

// Memoized Version
int uniquePaths(int m, int n, vector<vector<int>> &dp)
{
	// base case
	if(m==0 && n==0)
	{
		return 1;
	}
	if(m<0 || n<0)
	{
		return 0;
	}
	// recursive call
	if(dp[m][n] != -1) return dp[m][n];
	int left = uniquePaths(m, n-1, dp);
	int up = uniquePaths(m-1, n, dp);

	return dp[m][n] = left+up;
}

// Tabulated Version - DP
int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	dp[0][1] = 1;

	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	return dp[m][n];
}

// Optimized version
int uniquePathsO(int m, int n)
{
	vector<int> dp(n+1,0);
	dp[1] = 1;

	for(int i=1; i<=m; i++)
	{
		vector<int> temp(n+1,0);
		for(int j=1; j<=n; j++)
		{
			temp[j] = temp[j-1] + dp[j];
		}
		dp = temp;
	}
	return dp[n];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	cin>>m>>n;
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	cout<<uniquePaths(m-1,n-1, dp)<<endl;
	cout<<uniquePaths(m, n)<<endl;
	cout<<uniquePathsO(m, n)<<endl;
}

