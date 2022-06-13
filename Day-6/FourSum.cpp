#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.


sample I/O:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/
vector<vector<int> > fourSum(vector<int>& nums, int target) 
{
    //sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > output;
    for(int i=0; i<n-3; i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        for(int j=i+1; j<n-2; j++)
        {
            if(j>i+1 && nums[j]==nums[j-1])
            {
                continue;
            }
            int l=j+1, h=n-1, tSum = target-(nums[i]+nums[j]);
            while(l<h)
            {
                if(nums[l]+nums[h] < tSum) l++;
                else if(nums[l]+nums[h] > tSum) h--;
                else
                {
                    vector<int> ans = {nums[i], nums[j], nums[l], nums[h]};
                    output.push_back(ans);
                    
                    while(l<h && nums[l]==nums[l+1])
                    {
                        l++;
                    }
                    while(l<h && nums[h]==nums[h-1])
                    {
                        h--;
                    }
                    l++;
                    h--;
                }
            }
        }
    }
    return output;
}

int main()
{
    int n, target;
    cin>>n>>target;
    vector<int> input;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }

    vector<vector<int> > output = fourSum(input, target);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i][0]<<" "<<output[i][1]<<" "<<output[i][2]<<" "<<output[i][3]<<endl;
    }
    
}