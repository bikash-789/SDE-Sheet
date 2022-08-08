#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &arr, int target)
{
    //return the index
    //return -1 if it doesn't exist
    int start = 0;
    int end = arr.size()-1;

    while(start<=end)
    {
        //find the middle element
        // int mid = (start+end)/2;  // might be possible that (Start+end) exceeds the size of 'int' in cpp
        int mid = start + (end-start)/2;

        if(target == arr[mid])
        {
            return mid;
        }
        else if(target < arr[mid])
        {
            end = mid-1;
        }
        else start = mid+1;
    }
    return -1;
}

int main()
{
    int n, target, temp;
    cin>>n;
    
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>target;
    cout<<BinarySearch(arr, target)<<endl;
}