#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int s=0, e = arr.size()-1, mid;
        while(s<=e)
        {
            mid = s+(e-s)/2;
            if((mid>0 && mid<arr.size()-1) && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            {
                
                return mid;
            }
            else if(arr[mid] < arr[mid+1])
            {
                s=mid+1;
            }
            else e=mid-1;
        }
        return -1;
}

int main()
{
    int n, temp;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<peakIndexInMountainArray(arr)<<endl;
}