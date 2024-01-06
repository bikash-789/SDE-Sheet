#include <bits/stdc++.h> 
using namespace std;

// Problem Link:
// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int mod = (int)(1e9 + 7);

int countSubsetsSumToK(vector<int> &arr, int n, int k)
{
    // Tabulation
    vector<int> prev(k+1, 0), temp(k+1, 0);

    // if the only element is present and it's equal to 0
    // Then there is two possible subsets whose sum is 0: with element and without element
    if(arr[0] == 0) prev[0] = 2;
    // if the only element is not zero then there is only one subsets whose sum is 0
    else prev[0] = 1;

    // if only element is not zero and it's less than K
    if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

    // start with first element in given array
    for(int i=1; i<n; i++)
    {
        // Count the possible subsets with sum equal to 'target'
        for(int target=0; target<=k; target++)
        {
            int notTake = prev[target];
            int take = 0;
            if(arr[i] <= target)
            {
                take = prev[target-arr[i]];
            }
            temp[target] = (take + notTake) % mod;
        }
        prev = temp;
    }
    return prev[k];
}


int countPartitions(int n, int d, vector<int> &arr) {
    int s = 0;
    for(int i=0; i<n; i++)
    {
        s += arr[i];
    }
    if((s-d) < 0 || (s-d)%2) return 0;
    return countSubsetsSumToK(arr, n, (s-d)/2);
}


int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n,d;
  cin>>n>>d;
  vector<int> arr(n, 0);
  for(int j=0; j<n; j++)
  {
    cin>>arr[j];
  }
  cout<<countPartitions(n, d, arr)<<endl;
}