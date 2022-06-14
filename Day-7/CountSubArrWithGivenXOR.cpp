#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();

    unordered_map<int, int> hashMap;

    //idea: count no of Y such that {Y^K = XOR}
    //where [...a]^[..b] = [...c] ; a=0..i, b=i+1,...n and c=0,...n in an array
    //[...a] = Y; [..b] = K and [...c] = XOR

    int count=0, xoR = 0;
    for(int i=0; i<n; i++)
    {
        xoR ^= arr[i];

        if(xoR == x) count++;

        int Y = xoR ^ x;
        if(hashMap[Y]) count+=hashMap[Y];

        hashMap[xoR]++;
    }
    return count;
}
int main()
{
    int n,val;
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
}