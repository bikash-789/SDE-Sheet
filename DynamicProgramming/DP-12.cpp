// Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
using namespace std;

// given the target, if there is subset whose sum equals to target upto given index.
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
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


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin>>t;
  while(t--)
  {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for(int j=0; j<n; j++)
    {
        cin>>arr[j];
    }
    cout<<subsetSumToK(n, k, arr)<<endl;
  }
  
}