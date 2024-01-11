#include <bits/stdc++.h> 
using namespace std;
// Problem Link: https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-a-string-palindrome_985293?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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

int minimumInsertions(string &str)
{
	// Write your code here.
	int n = str.size();
	return (n - longestPalindromeSubsequence(str));
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s;
  cin>>s;
  cout<<minimumInsertions(s)<<endl;
}