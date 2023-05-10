#include <iostream>
#include <vector>

using namespace std;

void findCombinationSum(vector<int>& candidates, int target, int index, vector<vector<int> >& combinations, vector<int> combination)
{
    if(index >= candidates.size())
    {
        if(target == 0)
        {
            combinations.push_back(combination);
        }
        return;
    }

    // pick the current element
    if(candidates[index] <= target)
    {
        combination.push_back(candidates[index]);
        findCombinationSum(candidates, target-candidates[index], index, combinations, combination);
        combination.pop_back();
    }
    // do not pick the element
    findCombinationSum(candidates, target, index+1, combinations, combination);
}
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > combinations;
    vector<int> combination;

    findCombinationSum(candidates, target, 0, combinations, combination);
    return combinations;
}

void printCombinations(vector<vector<int> > combinations)
{
    for(int i=0; i<combinations.size();i++)
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
    int n;
    cin>>n;
    vector<int> candidates;
    int target, val;
    while(n--)
    {
        cin>>val;
        candidates.push_back(val);
    }
    cin>>target;
    vector<vector<int> > combinations = combinationSum(candidates, target);
    printCombinations(combinations);
}