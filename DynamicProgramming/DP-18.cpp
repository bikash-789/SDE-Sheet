#include <bits/stdc++.h> 
using namespace std;

// Problem Link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int f(vector<int>&num, int x, int ind, vector<vector<int>> &dp)
{
    if(x == 0)
    {
        return 0;
    }
    // base case
    if(ind == 0)
    {
        if(x == num[ind])
        {
            return 1;
        }
        if(num[ind] <= x && x%num[ind] == 0)
        {
            return x/num[ind];
        }
        return 1e9;
    }
    if(dp[ind][x] != -1) return dp[ind][x];
    int notTake = f(num, x, ind-1, dp);
    int take = 1e9;
    if(num[ind] <= x)
    {
        take = 1 + f(num, x-num[ind], ind, dp);
    }
    return dp[ind][x] = min(notTake, take);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = f(num, x, n-1, dp);
    return ans!=1e9?ans:-1;
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n,x;
  cin>>n>>x;
  vector<int> arr(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>arr[j];
  }
  cout<<minimumElements(arr, x)<<endl;
}