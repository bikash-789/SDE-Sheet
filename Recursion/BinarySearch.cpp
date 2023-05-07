#include <iostream>
#include <vector>
using namespace std;

int helperFunc(vector<int> arr, int key, int start, int end)
{
    // base case
    if(start <= end)
    {
        int mid = start + (end - start)/2;
        // check middle
        if(arr[mid] == key)
        {
            return mid;
        }

        // check right half
        else if(arr[mid] < key)
        {
            return helperFunc(arr, key, mid+1, end);
        }
        // check left half
        return helperFunc(arr, key, start, mid-1);
    }
    return -1;
}

int binarySearch(vector<int> arr, int key)
{
    int ans = helperFunc(arr, key, 0, arr.size()-1);
    return ans;
}
int main()
{
    vector<int> arr;
    int n, val, key;
    cin>>n;
    while(n--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cin>>key;
    cout<<binarySearch(arr, key)<<endl;
}