#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;



vector<vector<int> > pairSum(vector<int> &arr, int s)
{
    //pairSum
    unordered_map<int, int> numFreq;
    vector<vector<int> > output;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        if(numFreq[s-arr[i]])
        {
            for(int j=0; j<(numFreq[s-arr[i]]); j++)
            {
                vector<int> ans;
                ans.push_back(min(arr[i], (s-arr[i])));
                ans.push_back(max(arr[i], (s-arr[i])));
                output.push_back(ans);
            }
        }
        numFreq[arr[i]]++;
    }
    sort(output.begin(), output.end());
    return output;
}
int main()
{
    //2 3 -3 3 -2 t=0
    int n, t;
    cin>>n>>t;
    int val;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
    vector<vector<int> > output = pairSum(input, t);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i][0]<<" "<<output[i][1]<<endl;
    }
}