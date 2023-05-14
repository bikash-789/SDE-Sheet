#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &nums, int start, int mid, int end)
{
    int i = start, j = mid+1;
    int countRevPairs = 0;
    // Count reverse pairs here
    for(int i=start; i<=mid; i++)
    {
        while(j <= end && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        countRevPairs += j-(mid+1);
    }
    i = start, j = mid+1;
    // Merge the arrays
    vector<int> temp;
    
    while(i<=mid && j<=end)
    {
        if(nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else temp.push_back(nums[j++]);
    }

    while(i<=mid) temp.push_back(nums[i++]);
    while(j<=end) temp.push_back(nums[j++]);
    
    i=start;
    while(i<=end)
    {
        nums[i] = temp[i-start];
        i++;
    }
    return countRevPairs;
}

int mergeSort(vector<int> &nums, int start, int end)
{
    if(start >= end)
    {
        return 0;
    }
    int mid = (start+end)/2;
    int countRevPairs = mergeSort(nums, start, mid);
    countRevPairs += mergeSort(nums, mid+1, end);
    countRevPairs += merge(nums, start, mid, end);
    return countRevPairs;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size()-1);
}
int main()
{
    int n, val;
    vector<int> nums;
    cin>>n;
    while(n--)
    {
        cin>>val;
        nums.push_back(val);
    }
    cout<<reversePairs(nums)<<endl;
}