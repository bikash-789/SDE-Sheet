#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int f(vector<int> &weight, vector<int> &value, int maxWeight, int ind, vector<vector<int>> &dp)
{
  // base case
  if(ind == 0)
  {
    if(weight[ind] <= maxWeight)
    {
      return value[ind];
    }
    return 0;
  } 
  if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];

  int notTake = f(weight, value, maxWeight, ind-1, dp);
  int take = 0;
  if(weight[ind] <= maxWeight)
  {
    take = f(weight, value, maxWeight-weight[ind], ind-1, dp) + value[ind];
  }
  return dp[ind][maxWeight] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
  // Write your code here.
  vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
  return f(weight, value, maxWeight, n-1, dp);
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, maxWeight;
  cin>>n;
  vector<int> weight(n, 0), value(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>weight[j];
  }
  for(int j=0; j<n; j++)
  {
    cin>>value[j];
  }
  cin>>maxWeight;
  cout<<knapsack(weight, value, n, maxWeight)<<endl;
}