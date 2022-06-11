#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    unordered_map<int, int> map;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        map[arr.at(i)] = map[arr.at(i)]+1;
    }
    
    int greaterBy = n/3;
    vector<int> output;
    for(auto i: map)
    {
        if(i.second >greaterBy)
        {
            output.push_back(i.first);
        }
    }
    return output;
}

int main()
{
    vector<int> input;
    int n;
    cin>>n;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
    vector<int> output = majorityElementII(input);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
