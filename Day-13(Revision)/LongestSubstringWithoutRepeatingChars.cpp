#include <iostream>
#include <unordered_map>
using namespace std;


int uniqueSubstrings(string s)
{
    unordered_map<char, int> hashMap;
    int l=0, r=0, n=s.size(), ans=0;
    while(r<n)
    {
        if(hashMap[s[r]])
        {
            l = max(l, hashMap[s[r]]);
        }
        hashMap[s[r]]=r+1;
        ans = max(ans, (r-l)+1);
        r++;
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<uniqueSubstrings(s)<<endl;
}       