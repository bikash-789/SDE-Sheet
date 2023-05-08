#include <iostream>
using namespace std;

void generateSubsets(vector<int> arr, vector<int> subsets, int index)
{
    // base case
    if(index == arr.size())
    {
        if(subsets.size()==0)
        {
            cout<<"[]"<<endl;
        }
        // print the subset array
        for(int i=0; i<subsets.size(); i++)
        {
            cout<<subsets[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {

        // include the current element pointed by index
        subsets.push_back(arr[index]);
        // recursive call
        generateSubsets(arr, subsets, index+1);


        // exclude the current element pointed by index
        subsets.pop_back();
        // recursive call
        generateSubsets(arr, subsets, index+1);
    }
}
int main()
{
    int n, val;
    vector<int> arr, subsets;
    cin>>n;
    while(n--)
    {
        cin>>val;
        arr.push_back(val);
    }
    generateSubsets(arr, subsets, 0);
}