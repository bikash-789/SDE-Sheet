#include <bits/stdc++.h> 
using namespace std;
int lcs(string s, string t)
{
	int m = s.size();
	int n = t.size();
	vector<int> prev(n+1, 0), current(n+1, 0);
	
	for(int ind1 = 1; ind1 <= m; ind1++)
	{
		for(int ind2 = 1; ind2 <= n; ind2++)
		{
			if(s[ind1-1] == t[ind2-1])
			{
				current[ind2] = 1 + prev[ind2-1];
			}
			else{
				current[ind2] = max(prev[ind2], current[ind2-1]);
			}
		}
		prev = current;
	}
	return current[n];
}

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return lcs(s1, s2);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s;
  cin>>s;
  cout<<longestPalindromeSubsequence(s)<<endl;
}