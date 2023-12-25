#include <bits/stdc++.h>
using namespace std;

// Frog jump with K distance
int findMinDistance(int ind, vector<int> &heights, int k)
{
	if(ind==0)
	{
		return 0;
	}

	int minsteps = INT_MAX;
	int jump;
	for(int i=1; i<=k; i++)
	{
		if(ind-i>=0)
		{
			jump = abs(heights[ind-i]-heights[ind]) + findMinDistance(ind-1, heights, k);
			minsteps = min(jump, minsteps);
		}
	}
	return minsteps;
}

// Find the 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,k,h;
	cin>>n;
	vector<int> heights(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>h;
		heights[i] = h;
	}
	cin>>k;
	cout<<findMinDistance(n-1, heights, k)<<endl;
}
