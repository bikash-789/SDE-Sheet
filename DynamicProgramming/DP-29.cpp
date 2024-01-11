#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string &a, string &b) {
  // Write your code here.
  int m = a.size();
  int n = b.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int len = m + n - dp[m][n];
  string superseq = "";

  int i = m, j = n;

  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      superseq += a[i - 1];
      i--,j--;
    } else if (dp[i - 1][j] > dp[i][j - 1])
      {
        superseq += a[i-1];
        i--;
      }
      else {
        superseq += b[j-1];
        j--;
      }
  }
  while(i>0)
  {
	  superseq += a[i-1];
	  i--;
  }
  while(j>0)
  {
	  superseq += b[j-1];
	  j--;
  }
  reverse(superseq.begin(), superseq.end());
  return superseq;
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s,t;
  cin>>s;
  cin>>t;
  cout<<shortestSupersequence(s,t)<<endl;
}