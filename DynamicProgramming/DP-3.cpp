#include <bits/stdc++.h>
using namespace std;

// Frog Jump problem
// Find minimum energy spent by frog to jump from n-th level to zero
// The Frog can either take one step or two step at a time
int findMinEnergy(int ind, vector<int> &energy)
{
	// base case
	if(ind == 0)
	{
		return 0;
	}

	int takeOneStep = findMinEnergy(ind-1, energy) + abs(energy[ind]-energy[ind-1]);
	int takeTwoStep = INT_MAX;
	if(ind > 1)
	{
		takeTwoStep = findMinEnergy(ind-2, energy) + abs(energy[ind]-energy[ind-2]);
	}

	return min(takeOneStep, takeTwoStep);
}

// Memoization solution
int findMinEnergyMem(int ind, vector<int> &energy, vector<int> &dp)
{
	//base case
	if(ind == 0)
	{
		dp[ind] = 0;
		return dp[ind];
	}

	if(dp[ind-1] == -1)
	{
		dp[ind-1] = findMinEnergy(ind-1, energy);
	}
	int takeOneStep = dp[ind-1] + abs(energy[ind]-energy[ind-1]);
	int takeTwoStep = INT_MAX;

	if(ind > 1)
	{
		if(dp[ind-2] == -1)
		{
			dp[ind-2] = findMinEnergy(ind-2, energy);
		}
		takeTwoStep = dp[ind-2] + abs(energy[ind]-energy[ind-2]);
	}
	return min(takeOneStep, takeTwoStep);
}
// Optimized Solution
int findMinEnergyOpt(int n, vector<int> &energy)
{
	// start with base case
	int prev = 0, prev2 = 0;
	for(int i=1; i<n; i++)
	{
		int fs = prev + abs(energy[i-1]-energy[i]);
		int ss = INT_MAX;
		if(i>1) ss = prev2 + abs(energy[i-2] - energy[i]);

		int curi = min(fs, ss);
		prev2 = prev;
		prev = curi;
	}
	return prev;
 }

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n,e;

	cin>>t;
	for(int k=0; k<t; k++)
	{
		cin>>n;
		vector<int> energy(n, 0);
		vector<int> dp(n, -1);
		for(int i=0; i<n; i++)
		{
			cin>>e;
			energy[i] = e;
		}
		cout<<findMinEnergy(n-1, energy)<<endl;
		// cout<<findMinEnergyMem(n-1, energy, dp)<<endl;
		cout<<findMinEnergyOpt(n, energy)<<endl;
	}
	
}
