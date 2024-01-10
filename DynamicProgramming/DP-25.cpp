#include <bits/stdc++.h> 
using namespace std;

int lcs(string &str1, string &str2){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxlen = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = 0;
            maxlen = max(maxlen, dp[i][j]);
        }
    }
    return maxlen;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s,t;
  cin>>s;
  cin>>t;
  cout<<lcs(s,t)<<endl;
}