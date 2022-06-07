#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    unordered_map<int, int> freqTable;
    for(int i=0; i<n; i++)
    {
        if(freqTable[arr[i]])
        {
            return arr[i];
        }
        freqTable[arr[i]] = 1;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> input;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
    cout<<findDuplicate(input, n);
}