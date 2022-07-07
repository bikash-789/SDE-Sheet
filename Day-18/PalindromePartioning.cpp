#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement

You are given a string 'S'. Your task is to partition 'S' such that every substring of 
the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

Note: A substring is a contiguous segment of a string.

For Example:

For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.

*/

bool isPalindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}

void helperFunc(string s, vector<vector<string>> &ans, vector<string> &path, int indx)
{
    //base case
    if(indx >= s.size())
    {
        ans.push_back(path);
        return;
    }

    //recursive call and small work
    for(int i=indx; i<s.size(); i++)
    {
        //check for palindrome 
        if(isPalindrome(s, indx, i))
        {
            path.push_back(s.substr(indx, i-indx+1));
            helperFunc(s, ans, path, i+1);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> path;
    helperFunc(s, ans, path, 0);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    vector<vector<string>> ans = partition(s);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}