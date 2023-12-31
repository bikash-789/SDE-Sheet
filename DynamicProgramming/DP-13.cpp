#include <bits/stdc++.h> 
using namespace std;

// Problem Link: https://www.codingninjas.com/studio/problems/partition-equal-subset-sum-_892980?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

bool subsetSumToK(vector<int> &arr, int n, int k)
{
	vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
	for(int i=0; i<n; i++)
	{
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=k; target++)
        {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(target >= arr[ind]) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = notTake | take;
        }
    }

	return dp[n-1][k];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	// first find the sum of arr
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += arr[i];
	}
	if(sum % 2) return false;
	bool left = subsetSumToK(arr, n, sum/2);
	return left;
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
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int j=0; j<n; j++)
    {
        cin>>arr[j];
    }
    cout<<canPartition(arr, n)<<endl;
  }
  
}
