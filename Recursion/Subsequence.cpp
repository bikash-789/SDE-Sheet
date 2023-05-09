#include <iostream>
#include <vector>

using namespace std;

void findSubseq(vector<int> &nums, vector<int> subseq, int index)
{
    // base case
    if(index >= nums.size())
    {
        // Print the subsequence array
        for(int i=0; i<subseq.size(); i++)
        {
            cout<<subseq[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // Recursive call
    // include the element
    subseq.push_back(nums[index]);
    findSubseq(nums, subseq, index+1);

    // exclude the element
    subseq.pop_back();
    findSubseq(nums, subseq, index+1);
}

void generateAllSubsequence(vector<int> nums)
{
    vector<int> subseq;
    findSubseq(nums, subseq, 0);
}
int main()
{
    int n, val;
    cin>>n;
    vector<int> nums;
    while(n--)
    {
        cin>>val;
        nums.push_back(val);
    }
    generateAllSubsequence(nums);
}