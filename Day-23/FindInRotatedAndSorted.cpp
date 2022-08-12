#include <iostream>
#include <vector>

using namespace std;

//finding the pivot element index
int findPivotIndex(vector<int> &arr)
{
    int start=0, end=arr.size()-1, mid;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        if(arr[mid] >= arr[0])
        {
            start = mid+1;
        }
        else if(arr[mid] < arr[0])
        {
            end = mid-1;
        }
    }
    return end;
}

//binary search algorithm
int BS(vector<int> &arr, int start, int end, int target)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target < arr[mid])
        {
            // move to left
            return BS(arr, start, mid - 1, target);
        }
        else if (target > arr[mid])
            return BS(arr, mid + 1, end, target);
        else
            return mid;
    }
    // if not found in array
    return -1;
}

//Search algorithm
int search(vector<int> &nums, int target)
{
    // find the pivot
    int pivotIndex = findPivotIndex(nums);

    if(target >= nums[0] && target <= nums[pivotIndex]) return BS(nums, 0, pivotIndex, target);

    return BS(nums, pivotIndex + 1, nums.size() - 1, target);
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
    cout<<search(arr, target)<<endl;
}