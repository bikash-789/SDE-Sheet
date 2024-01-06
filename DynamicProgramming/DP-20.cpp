#include <bits/stdc++.h> 
using namespace std;
// Problem Link: https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


long countWaysToMakeChange(vector<int>&denominations, int n, int value) {
  // Write your code here
  vector<long> prev(value+1), curr(value+1);
  for(int i=0; i<=value; i++)
  {
      prev[i] = i % denominations[0] == 0;
  }
  for(int ind=1; ind<n; ind++)
  {
      for(int target = 0; target<=value; target++)
      {
          curr[target] = prev[target];
          if(target >= denominations[ind])
          {
              curr[target] += curr[target-denominations[ind]];
          }
      }
      prev = curr;
  }
  return prev[value];
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n,value;
  cin>>n>>value;
  vector<int> arr(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>arr[j];
  }
  cout<<countWaysToMakeChange(arr, n, value)<<endl;
}