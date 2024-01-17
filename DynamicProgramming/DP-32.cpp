#include <bits/stdc++.h>
using namespace std;

bool f(int i, int j, string pattern, string text, vector<vector<int>> &dp)
{
   // base case
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   
   if(j<0 && i>=0) 
   {
      for(int ind = 0; ind<=i; ind++)
      {
         if(pattern[ind] != '*') return false;
      }
      return true;
   }
   
   if(dp[i][j] != -1) return dp[i][j];
   // recursive call
   if(pattern[i] == text[j] || pattern[i] == '?')
   {
      return dp[i][j] = f(i-1, j-1, pattern, text, dp);
   }
   else if(pattern[i] == '*')
   {
      return dp[i][j] = f(i-1, j, pattern, text, dp) || f(i, j-1, pattern, text, dp);
   }
   return dp[i][j] = 0;
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int m = pattern.size();
   int n = text.size();
   vector<vector<int>> dp(m, vector<int>(n,-1));
   return f(m-1, n-1, pattern, text, dp);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string pattern,text;
  cin>>pattern;
  cin>>text;
  cout<<wildcardMatching(pattern,text)<<endl;
}

