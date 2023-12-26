#include <bits/stdc++.h>
using namespace std;
// Problem link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

int uniquePaths(int m, int n) {
	// base case
	if(m==0 && n==0)
	{
		return 1;
	}

	// recursive call
	int left = uniquePaths(m, n-1);
	int up = uniquePaths(m-1, n);

	return left+up;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	cin>>m>>n;
	cout<<uniquePaths(m-1,n-1)<<endl;
}