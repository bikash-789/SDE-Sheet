#include <bits/stdc++.h> 
using namespace std;
// Problem Link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum._842494?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += arr[i];

	vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
	for(int i=0; i<n; i++)
	{
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=sum; target++)
        {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(target >= arr[ind]) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = notTake | take;
        }
    }
	int mini = 1e9;
	for(int s1=0; s1<=sum/2; s1++)
	{
		if(dp[n-1][s1] == true)
		{
			mini = min(mini, abs(s1 - (sum-s1)));
		}
	}
	return mini;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  cin>>n;
  vector<int> arr(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>arr[j];
  }
  cout<<minSubsetSumDifference(arr, n)<<endl;
}