#include <bits/stdc++.h>
using namespace std;


// Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349

// Recursive approach
int f(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if(i==0 && j==0) return grid[i][j];

    // edge case
    if(i<0 || j<0) return INT_MAX;

    int left = f(i, j-1, grid);
    int up = f(i-1, j, grid);
    return  grid[i][j] + min(left, up);
}

int minSumPathRecursive(vector<vector<int>> &grid) {
    // Write your code here.
    return f(grid.size()-1, grid[0].size()-1, grid);
}

// Tabulation + Optimization
int minSumPath(vector<vector<int>> &grid)
{
	int row = grid.size();
	int col = grid[0].size();

	vector<int> dp(col, 0);

	for(int i=0; i<row; i++)
	{
		vector<int> temp(col, 0);
		for(int j=0; j<col; j++)
		{
			if(i==0 && j==0){
				temp[i] = grid[i][j];
			}
			else{
				int left = grid[i][j];
				if(j>0) left+= temp[j-1];
				else left += 1e9;

				int up = grid[i][j];
				if(i>0) up += dp[j];
				else up += 1e9;

				temp[j] = min(up, left);
			}
		}
		dp = temp;
	}
	return dp[col-1];
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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
	cout<<minSumPath(grid)<<endl;
}
