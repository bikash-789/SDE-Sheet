#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Problem 1- Print all the subsequences of the given array
void printSubseq(int i, vector<int> &subseq, int n, int arr[])
{
    //base case
    if(i>=n)
    {
        for(auto it : subseq)
        {
            cout<<it<<" ";
        }
        if(!subseq.size()) cout<<"[]";
        cout<<endl;
        return;
    }

    //small work and recursive call
    
    //include first element
    subseq.push_back(arr[i]);
    printSubseq(i+1, subseq, n, arr);
    subseq.pop_back();

    //do not include first element
    printSubseq(i+1, subseq, n, arr);

}


//Problem 2- Print all the subsequences whose sum is equal to K of the given array
void printSubseqSum(int arr[], int n, int i, vector<int> &subseq, int K)
{
    //base case
    if(i>=n)
    {
        if(K==0)
        {
            //print the subseq
            for(auto it : subseq)
            {
                cout<<it<<" ";
            }
            if(!subseq.size()) cout<<"[]";
            cout<<endl;
        }
        return;
    }

    //recursive call and small work

    //include
    subseq.push_back(arr[i]);
    printSubseqSum(arr, n, i+1, subseq, K-arr[i]);
    subseq.pop_back();


    //do not include
    printSubseqSum(arr, n, i+1, subseq, K);
}

//Problem 3: Count the no. of subsequences whose sum is equal to K
int countSubSeqSum(int arr[], int n, int i, int K)
{
    //base case
    if(i>=n)
    {
        if(K==0)
        {
            return 1;
        }
        return 0;
    }

    //recursive call and small work
    int l = countSubSeqSum(arr, n, i+1, K-arr[i]);
    int r = countSubSeqSum(arr, n, i+1, K);
    return l+r;
}


//Problem 4: Print all the possible combinations whose sum is equal to K
void combinationSum(int i, int arr[], int K, vector<int> &combs, int n)
{
    //base case
    if(i>=n)
    {
        if(K==0)
        {
            //print the combs
            for(auto i: combs)
                cout<<i<<" ";
            if(!combs.size()) cout<<"[]";
            cout<<endl;
        }
        return;
    }

    //recursive call and small work
    
    //include the element
    if(K>=arr[i])
    {
        combs.push_back(arr[i]);
        combinationSum(i, arr, K-arr[i], combs, n);
        combs.pop_back();
    }
    
    //do not include the element
    combinationSum(i+1, arr, K, combs, n);

}


//Problem: 5 Return all the unique combinations whose sum is equal to target (K)
void findCombinationsII(int index, vector<int> &candidates, int target,int n, vector<int> &ds, vector<vector<int>> &ans)
{
    //base case
    if(target==0)
    {
        ans.push_back(ds);
        return;
    }

    //recursive call and small work
    for(int i=index; i<n-1; i++)
    {
        if(i>index && candidates[i]==candidates[i-1]) continue;

        if(candidates[i]>target) break;

        ds.push_back(candidates[i]);
        findCombinationsII(i+1, candidates, target-candidates[i], n, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    findCombinationsII(0, candidates, target, candidates.size(), ds, ans);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 4;
    vector<vector<int>> ans = combinationSum2(arr, target);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}