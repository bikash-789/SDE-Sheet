#include <iostream>
#include <vector>

using namespace std;

//implement Binary Search algorithm using recursive method

//helper function
int helperFunc(vector<int> &arr, int start, int end, int target)
{
    if(start<=end)
    {
        int mid = start + (end-start)/2;

        if(target < arr[mid])
        {
            //move to left
            return helperFunc(arr, start, mid-1, target);
        }
        else if(target > arr[mid]) return helperFunc(arr, mid+1, end, target);
        else return mid;
    }
    //if not found in array
    return -1;
}

int binarySearch(vector<int> &arr, int target)
{
    return helperFunc(arr, 0, arr.size()-1, target);
}
int main()
{
    int n, temp, target;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    
    cin>>target;
    cout<<binarySearch(arr, target)<<endl;
}