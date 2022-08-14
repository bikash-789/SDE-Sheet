#include <iostream>
#include <vector>

using namespace std;

int findRotationCount(vector<int> &arr)
{
    //It's basically [pivotIndex + 1] 
    int start=0, end=arr.size()-1, mid;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]>=arr[0])
        {
            start = mid+1;
        }
        else end = mid-1;
    }
    return end+1;
}

int main()
{
    int n,temp;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<findRotationCount(arr)<<endl;
}