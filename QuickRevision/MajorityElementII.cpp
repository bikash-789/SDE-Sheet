#include <iostream>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int elem1 = INT_MIN, elem2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != elem2)
        {
            elem1 = nums[i];
            cnt1++;
        }
        else if (cnt2 == 0 && nums[i] != elem1)
        {
            elem2 = nums[i];
            cnt2++;
        }
        else if (elem1 == nums[i])
            cnt1++;
        else if (elem2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (elem1 == nums[i])
            cnt1++;
        else if (elem2 == nums[i])
            cnt2++;
    }
    vector<int> elems;
    if (cnt1 > nums.size() / 3)
        elems.push_back(elem1);
    if (cnt2 > nums.size() / 3)
        elems.push_back(elem2);

    return elems;
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

    vector<int> elems = majorityElement(nums);
    for(int i=0; i<elems.size(); i++)
    {
        cout<<elems[i]<<" ";
    }
    cout<<endl;
}