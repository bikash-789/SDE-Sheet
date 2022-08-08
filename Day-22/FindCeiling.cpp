#include <iostream>
#include <vector>

using namespace std;


int findCeiling(vector<int> &arr, int target)
{
    //find the ceiling from the given array
    //A ceiling is defined as number which is greater than or equal to target element in the given array
    

    //Approach:
    //Apply binary search in the given array to find the target element

    //Assuming the array given is sorted 

    int s=0, e=arr.size()-1;
    while(s<=e)
    {
        //if arr[mid] is less than target move to right
        int mid = s+(e-s)/2;
        if(arr[mid]<target)
        {
            s = mid+1;
        }
        //if arr[mid] is greater than target move to left
        else e = mid-1;
    }
    return arr[s];
}

int main()
{
    int n, target;
    cin>>n;
    int temp;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>target;
    cout<<findCeiling(arr, target)<<endl;    
}