#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/edit-distance/description/

// Recursive approach
int f(int i, int j, string word1, string word2)
{
	// base case
	if(i<0) return j+1;
	if(j<0) return i+1;

	// recursive call
	if(word1[i] == word2[j])
	{
		return f(i-1, j-1, word1, word2);
	}
	else{
		int del = 1 + f(i-1, j, word1, word2);
		int rep = 1 + f(i-1, j-1, word1, word2);
		int ins = 1 + f(i, j-1, word1, word2);
		return min(del, min(rep, ins));
	}
}

// Tabulation + Optimized
int minDistance(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n + 1, 0), current(n + 1, 0);

        // base case
        for (int j = 0; j <= n; j++)
            prev[j] = j;

        for (int i = 1; i <= m; i++) {
            current[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    current[j] = prev[j - 1];
                } else {
                    // delete , insert, replace
                    current[j] =
                        1 + min(prev[j], min(current[j - 1], prev[j - 1]));
                }
            }
            prev = current;
        }
        return prev[n];
    }

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string word1,word2;
  cin>>word1;
  cin>>word2;
  cout<<minDistance(word1, word2)<<endl;
}