#include <bits/stdc++.h> 
using namespace std;


int findWays(vector<int> &arr, int k) {
  // Write your code here.
  int n = arr.size();
  int mod = 1e9 + 7;
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));
  if(arr[0] == 0) dp[0][0] = 2;
  else dp[0][0] = 1;

  if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

  
  for (int ind = 1; ind < n; ind++) {
    for (int target = 0; target <= k; target++) {
		int notTake = dp[ind-1][target];
		int take = 0;
      	if (target >= arr[ind]) {
        	take = dp[ind - 1][target - arr[ind]];
      	}
		dp[ind][target] = (take + notTake) % mod;
    }
  }
  return dp[n - 1][k];
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n,k;
  cin>>n>>k;
  vector<int> arr(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>arr[j];
  }
  cout<<findWays(arr, k)<<endl;
}