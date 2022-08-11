#include <iostream>
#include <vector>

using namespace std;

//Binary Search
int BS(vector<int> &arr, int start, int end, int target)
{
    while(start <= end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] < target)
        {
            //move to right
            start = mid+1;
        }
        else if(arr[mid] > target)
        {
            end = mid-1;
        }
        else return mid;
    }
    return -1;
}

//find position in an infinite sorted array
int findPosition(vector<int> &arr, int target)
{
    int start = 0;
    int end = 1;
    while(arr[end] < target)
    {
        //keep moving right
        int temp = end + 1;
        int boxsize = (end-start+1)*2;
        end = end + boxsize;
        start = temp;
    }
    int ans = BS(arr, start, end, target);
    return ans;
}

int main()
{
    int temp, target, n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }

    cin>>target;
    cout<<findPosition(arr, target)<<endl;
}