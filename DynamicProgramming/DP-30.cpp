#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);
int distinctSubsequences(string &str, string &sub)
{
	// base case
	int m = str.size();
	int n = sub.size();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for(int i=0; i<=m; i++)
	{
		dp[i][0] = 1;
	}
	
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(str[i-1] == sub[j-1])
			{
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
			}
			else dp[i][j] = (dp[i-1][j])%mod;
		}
	}
	return dp[m][n];
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string str,sub;
  cin>>str;
  cin>>sub;
  cout<<distinctSubsequences(str,sub)<<endl;
}