#include <iostream>
using namespace std;

void findCombinationSum(vector<int> &candidates, int target, int index, vector<vector<int> > &combinations, vector<int> &combination)
{
    if(target==0)
    {
        combinations.push_back(combination);
        return;
    }

    for(int i=index; i<candidates.size(); i++)
    {
        if(i != index && candidates[i-1] == candidates[i]) continue;
        if(target < candidates[i]) break;

        combination.push_back(candidates[i]);
        findCombinationSum(candidates, target-candidates[i], i+1, combinations, combination);
        combination.pop_back();
    }
}



vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<int> combination;
    sort(candidates.begin(), candidates.end());

    vector<vector<int> > combinations;
    findCombinationSum(candidates, target, 0,  combinations, combination);
    return combinations;
}

void printCombinations(vector<vector<int> > & combinations)
{
    for(int i=0; i<combinations.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<combinations[i].size(); j++)
        {
            if(j==combinations[i].size()-1)
            {
                cout<<combinations[i][j];
            }
            else cout<<combinations[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
}

int main()
{
    int n, val, target;
    cin>>n;
    vector<int> candidates;
    
    while(n--)
    {
        cin>>val;
        candidates.push_back(val);
    }
    cin>>target;
    vector<vector<int> > combinations = combinationSum2(candidates, target);
    printCombinations(combinations);
}