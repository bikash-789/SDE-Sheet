#include <bits/stdc++.h>
using namespace std;
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> dp(n, 0);
	for(int i=0; i<n; i++)
	{
		dp[i] = triangle[n-1][i];
	}

	for(int i=n-2; i>=0; i--)
	{
		vector<int> temp(n, 0);
		for(int j=0; j<=i; j++)
		{
			temp[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j+1]);
		}
		dp = temp;
	}
	return dp[0];
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin>>n;
  vector<vector<int>> triangle(n, vector<int>(n, 0));
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<=i; j++)
    {
      cin>>triangle[i][j];
    }
  }
  cout<<minimumPathSum(triangle, n)<<endl;
}