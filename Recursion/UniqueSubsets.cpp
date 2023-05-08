#include <iostream>
#include <vector>

using namespace std;

// Input : [1,2,2]
// Output: [[1, 2, 2], [1, 2], [2,2], [2], [1], []]
void findSubsets(vector<int> &arr, int index, vector<vector<int> > &subsets, vector<int> subset)
{
    subsets.push_back(subset);
    for(int i=index; i<arr.size(); i++)
    {
        if(i!=index && arr[i-1] == arr[i]) continue;
        subset.push_back(arr[i]);
        findSubsets(arr, i+1, subsets, subset);
        subset.pop_back();
    }
}
vector<vector<int> > findPossibleUniqueSubsets(vector<int> arr)
{
    vector<vector<int> > subsets;
    vector<int> subset;
    // sort the given integers
    sort(arr.begin(), arr.end());
    findSubsets(arr, 0, subsets, subset);
    return subsets;
}
int main()
{
    vector<int> arr;
    int n, val;
    cin>>n;
    while(n--){
        cin>>val;
        arr.push_back(val);
    }

    vector<vector<int> > subsets = findPossibleUniqueSubsets(arr);
    for(int i=0; i<subsets.size(); i++)
    {
        for(int j=0; j<subsets[i].size(); j++)
        {
            cout<<subsets[i][j]<<" ";
        }
        cout<<endl;
    }
}