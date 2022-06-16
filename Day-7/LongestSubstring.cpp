#include <iostream>
#include <unordered_map>
using namespace std;


int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char, int> map;
    int maxi=0, l=0, r=0, n=input.size();
    while(r<n)
    {
        if(map[input[r]])
        {
            l = max(l, map[input[r]]+1);
        }
        map[input[r]] = r;
        maxi=max(maxi, (r-l)+1);
        r++;
    }
    
    return maxi;
}

int main()
{
    string input;
    cin>>input;
    cout<<uniqueSubstrings(input)<<endl;
    
}