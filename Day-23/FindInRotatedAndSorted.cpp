#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(vector<int> &arr)
{
    
}

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

int search(vector<int> &nums, int target)
{
    // find the pivot (peak index)
    int peakIndex = findPivotIndex(nums);

    if (peakIndex == -1)
        return BS(nums, 0, nums.size() - 1, target);
    // search in left peak of peak
    int ans = BS(nums, 0, peakIndex, target);

    // if not found in left, search in right part of peak
    if (ans == -1)
        ans = BS(nums, peakIndex + 1, nums.size() - 1, target);

    return ans;
}