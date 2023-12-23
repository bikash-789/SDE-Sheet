#include <bits/stdc++.h>
using namespace std;

// Using memoization
int fibMemoization(int n, vector<int> &dp)
{
	if(n<=1){
		dp[n] = n;
		return n;
	}

	if(dp[n] != -1) return dp[n];
	dp[n] = fibMemoization(n-1, dp) + fibMemoization(n-2, dp);
	return dp[n];
}

// Using tabulation method
int fibTabulation(int n, vector<int> &dp)
{
	dp[0] = 0, dp[1] = 1;
	for(int i=2; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}
// Optimized
int fib(int n)
{
	int prev = 1, nextPrev = 0, current;
	
	for(int i=2; i<=n; i++)
	{
		current = prev + nextPrev;
		nextPrev = prev;
		prev = current;
	}
	return current;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);
	cout<<fibMemoization(n, dp)<<endl;
	vector<int>dp2(n+1);
	cout<<fibTabulation(n, dp2)<<endl;
	cout<<fib(n)<<endl;
}