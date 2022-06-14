#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int LongestSubsetWithZeroSum(vector <int> arr) 
{
    unordered_map<int, int> map;
    int n = arr.size();
    int ans = 0;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum==0)
        {
            ans = i+1;
        }
        else
        {
            if(map[sum])
            {
                ans = max(i-map[sum], ans);
            }
            else map[sum] = i;
        }
    }
    return ans;
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
    cout<<LongestSubsetWithZeroSum(input)<<endl;
}