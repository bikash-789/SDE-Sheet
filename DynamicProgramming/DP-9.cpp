#include <bits/stdc++.h>
using namespace std;
// Let's optimize the solution
int getMaxPathSum(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  int maxSum = -1e9;
  vector<int> dp(n,0);

  // since for the first row, the ans will be as it is
  for(int i=0; i<n; i++)
    dp[i] = matrix[0][i];
  
  // Iterate over the rows and find the max at each col
  for(int i=1; i<m; i++)
  {
    vector<int> temp(n,0);
    for(int j=0; j<n; j++)
    {
      int diagLeft = matrix[i][j];
      if(j>0) diagLeft += dp[j-1];
      else diagLeft += -1e9;

      int diagRight = matrix[i][j];
      if(j<n-1) diagRight += dp[j+1];
      else diagRight += -1e9;

      int up = matrix[i][j] + dp[j];

      temp[j] = max(diagLeft, max(up, diagRight));
    }
    dp = temp;
  }
  for(int j=0; j<n; j++)
  {
    maxSum = max(dp[j], maxSum);
  }
  return maxSum;
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int m, n;
  cin>>m>>n;
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      cin>>matrix[i][j];
    }
  }
  cout<<getMaxPathSum(matrix)<<endl;
}