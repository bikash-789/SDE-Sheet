#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{

    vector<int> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr[k-1]);
    ans.push_back(arr[n-k]);
    return ans;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> ans = kthSmallLarge(arr, n, k);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}