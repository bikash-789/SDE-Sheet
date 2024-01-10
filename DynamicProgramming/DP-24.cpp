#include <bits/stdc++.h> 
using namespace std;

string findLCS(int m, int n, string &s, string &t){
	// Write your code here.
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	for(int i=0; i<m; i++) dp[i][0] = 0;
	for(int j=0; j<n; j++) dp[0][j] = 0;

	for(int ind1 = 1; ind1 <= m; ind1++)
	{
		for(int ind2 = 1; ind2 <= n; ind2++)
		{
			if(s[ind1-1] == t[ind2-1])
			{
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
			}
			else{
				dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
			}
		}
	}

	int len = dp[m][n];
	string ans = "";
	for(int i=0; i<len;i++)
	{
		ans += '$';
	}
	
	int index = len-1;
	int i = m, j = n;
	while(i>0 && j>0)
	{
		if(s[i-1] == t[j-1])
		{
			ans[index] = s[i-1];
			index--;
			i--,j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			i--;
		}
		else j--;
	}
	return ans;
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s,t;
  cin>>s;
  cin>>t;
  int m = s.size();
  int n = t.size();
  cout<<findLCS(m,n,s,t)<<endl;
}