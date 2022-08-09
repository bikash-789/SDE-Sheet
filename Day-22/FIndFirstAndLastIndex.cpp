#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &arr, int target, bool isFirstIndex)
{
    int s=0, e=arr.size()-1, ans=-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(arr[mid] == target) 
        {
            ans = mid;
            if(isFirstIndex)
            {
                e=mid-1;
            }
            else s=mid+1;
        }
        else if(arr[mid] > target)
        {
            //search in left
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans;
}
vector<int> findFirstAndLastIndex(vector<int> &arr, int target)
{
    vector<int> ans;
    ans.push_back(search(arr, target, true));
    ans.push_back(search(arr, target, false));
    return ans;
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
    vector<int> ans = findFirstAndLastIndex(arr, target);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
}