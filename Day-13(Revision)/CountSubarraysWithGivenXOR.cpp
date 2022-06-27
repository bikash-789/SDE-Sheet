#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> hashMap;
    int xr=0, ans=0, y=0;
    for(int i=0; i<arr.size(); i++)
    {
        xr ^= arr[i];
        if(xr == x) ans++;
        y = xr ^ x;
        if(hashMap[y])
        {
            ans += hashMap[y];
        }
        hashMap[xr]++;
    }
    return ans;
}
int main()
{
    int n, val, x;
    cin>>n>>x;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<subarraysXor(arr, x)<<endl;

}