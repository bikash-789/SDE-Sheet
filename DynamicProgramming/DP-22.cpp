#include <bits/stdc++.h> 
using namespace std;
// Problem Link: https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int f(vector<int> &price, int ind, int N, vector<vector<int>> &dp)
{
  // base case
  if(ind==0)
  {
    return price[ind] * N;
  }
  if(dp[ind][N] != -1) return dp[ind][N];
  int notCut = f(price, ind-1, N, dp);
  int rodLength = ind+1;
  int cut = INT_MIN;
  if(rodLength <= N) cut = price[ind] + f(price, ind, N-rodLength, dp);
  
  return dp[ind][N] = max(cut, notCut);
}

int cutRod(vector<int> &price, int n) {
    // Write your code here.
  vector<vector<int>> dp(n, vector<int>(n+1, -1));

  return f(price, n-1, n, dp);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  cin>>n;
  vector<int> price(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>price[j];
  }
  cout<<cutRod(price, n)<<endl;
}