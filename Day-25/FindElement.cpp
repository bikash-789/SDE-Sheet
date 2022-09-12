#include <iostream>
#include <vector>

using namespace std;

//Problem link: https://www.codingninjas.com/codestudio/problems/1112654?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

int findUniqueElement(vector<int> &nums)
{
    //find the unique element in the given array of repeated elements.
    int l=0, h=nums.size()-2;
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(nums[mid] == nums[mid^1])
        {
            l=mid+1;
        }
        else h=mid-1;
    }
    return nums[l];
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<findUniqueElement(nums)<<endl;
}