#include <bits/stdc++.h> 
using namespace std;

// Recursive approach
int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c, vector<vector<vector<int>>> &dp) {
    // edge cases
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
    {
        return -1e8;
    }

    // base case
    if(i==r-1)
    {
        if(j1 == j2)
        {
            return grid[i][j1];
        }
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    // recursive approach
    int maxi = -1e8;
    for(int dj1=-1; dj1<=+1; dj1++)
    {
        for(int dj2=-1; dj2<=+1; dj2++)
        {
            int value = 0;
            if(j1==j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];

            value += f(i+1, j1+dj1, j2+dj2, grid, r, c, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, grid, r, c, dp);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin>>t;
  while(t--)
  {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<maximumChocolates(m, n, grid)<<endl;
  }
  
}