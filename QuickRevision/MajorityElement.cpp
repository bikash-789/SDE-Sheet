#include <iostream>
#include <vector>

using namespace std;


int majorityElement(vector<int> &nums)
{
    // find the majority element in the given integer array using Moore's Voting algorithm
    int majorityElem = nums[0];
    int majorityCount = 1;
    
    for(int i=1; i<nums.size(); i++)
    {
        if(majorityElem == nums[i])
        {
            majorityCount++;
        }
        else majorityCount--;

        // Now check if majorityCount value is equal to 0
        if(majorityCount == 0)
        {
            majorityCount = 1;
            majorityElem = nums[i];
        }
    }

    majorityCount = 0;
    // Now verify that there is Majority element by traversing through list
    for(int i=0; i<nums.size(); i++)
    {
        if(majorityElem == nums[i])
        {
            majorityCount++;
        }
    }

    if(majorityCount > nums.size()/2) return majorityElem;
    return -1; // -1 indicates no majority element in list

}
int main()
{
    int n,val;
    cin>>n;
    vector<int> nums;
    while(n--)
    {
        cin>>val;
        nums.push_back(val);
    }
    cout<<majorityElement(nums)<<endl;
}