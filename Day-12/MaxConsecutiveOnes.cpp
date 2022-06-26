#include <iostream>
#include <vector>
using namespace std;


int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                sum = 0;
            }
            else sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
}


int main()
{
    int n, val;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        nums.push_back(val);
    }
    cout<<findMaxConsecutiveOnes(nums)<<endl;
}