#include <iostream>
using namespace std;

int uniquePaths(int m, int n, int row, int col, vector<vector<int> > &dp)
{
    // base case
    if(row == m-1 && col == n-1)
    {
        return 1;
    }

    else if(row>=m || col>=n)
    {
        return 0;
    }

    // Recursive call
    if(dp[row][col] == -1) return dp[row][col] = uniquePaths(m, n, row+1, col, dp) + uniquePaths(m, n, row, col+1, dp);
    return dp[row][col];
}

int uniquePaths(int m, int n)
{
    vector<vector<int> > dp(m, vector<int>(n, -1));
    return uniquePaths(m, n, 0, 0, dp);
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m, n)<<endl;
}