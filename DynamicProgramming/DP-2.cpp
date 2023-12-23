#include <bits/stdc++.h>
using namespace std;

// Climbing Stairs Problem


// Recursive solution
// T - O(N^2)
// S - O(N)
int findPossWay(int n)
{
	if(n==0 || n==1){
		return 1;
	}

	int oneStep = findPossWay(n-1);
	int twoStep = findPossWay(n-2);
	return oneStep + twoStep;
}

// Memoization
// T - O(N)
// S - O(N) + O(N)
int findWayM(int n, vector<int> &dp)
{
	if(n==0 || n==1){
		dp[n] = 1;
		return 1;
	}

	if(dp[n-1] == -1)
	{
		dp[n-1] = findWayM(n-1, dp);
	}

	if(dp[n-2] == -1)
	{
		dp[n-2] = findWayM(n-2, dp);
	}

	return dp[n-1] + dp[n-2];
}

// Tabulation
// T - O(N)
int findWayT(int n)
{
	// start with base case
	int zeroth = 1, first = 1, second;

	if(n==0) return zeroth;
	if(n==1) return first;
	for(int i=2; i<=n; i++)
	{
		second = zeroth + first;
		zeroth = first;
		first = second;
	}

	return second;
}

// Main function
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << findPossWay(n) <<endl;
	vector<int> dp(n+1, -1);
	cout<<findWayM(n, dp)<<endl;
	cout<<findWayT(n)<<endl;
}

