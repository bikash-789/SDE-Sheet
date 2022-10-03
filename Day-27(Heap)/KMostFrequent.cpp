#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct Pair{
    int key, value;
    Pair(int key, int value):key(key), value(value)
   {
   }
};

struct compareCount{
   bool operator()(Pair const& p1, Pair const& p2)
   {
      return p1.value < p2.value;
   }
};

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<Pair, vector<Pair>, compareCount> pq;
    unordered_map<int, int> hashTable;
    for(int i=0; i<n; i++)
    {
        hashTable[arr[i]]++;
    }
    
    for (auto i : hashTable)
    {
        //cout<<i.first<<" "<<i.second<<endl;
        pq.push(Pair(i.first, i.second));
    }
    vector<int> ans;
    for(int i=0; i<k; i++)
    {
        int a = pq.top().key;
        ans.push_back(a);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int k, n, temp;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    vector<int> ans = KMostFrequent(n,k, arr);
    
    for(int i=0; i<k; i++)
    {
        cout<<ans[i]<<" ";
    }   
    cout<<endl;
}