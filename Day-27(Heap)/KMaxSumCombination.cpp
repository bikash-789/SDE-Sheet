#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> helperFunc(vector<int> a, vector<int> b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=n-1;
    priority_queue<int> pq;
    while(i>=0)
    {
        int j=n-1;
        while(j>=0)
        {
            pq.push(a[i]+b[j]);
            j--;
        }
        i--;
    }
    vector<int> ans;
    for(int i=0; i<k; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int> ans = helperFunc(a, b, n, k);
    return ans;
}

int main()
{
    vector<int> a, b;
    int n, k, temp;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        b.push_back(temp);
    }
    vector<int> ans = kMaxSumCombination(a,b,n,k);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}