#include <iostream>
#include <vector>


using namespace std;

//finding the pivot element index
int findDuplicatePivotIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size()-1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        //Checking if arr[mid] is pivot element or not
        if(mid < end && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        if(mid > start && arr[mid] < arr[mid-1])
        {
            return mid-1;
        }
        
        //if elements at middle, start and end are equal then skip the duplicates
        if(arr[mid] == arr[start] && arr[mid] == arr[end])
        {
            if(arr[start] > arr[start+1]) return start;
            start++;
            if(arr[end] < arr[end-1]) return end-1;
            end--;
        }
        else if(arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end])) {
            start = mid+1;
        }
        else end = mid-1;

    }
    return -1;
}

int binarySearch(vector<int> &arr, int start, int end, int target)
{
    int mid;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(target == arr[mid]) return mid;
        else if(target < arr[mid]) end = mid-1;
        else start = mid+1;
    }
    return -1;
}

int search(vector<int> &arr, int target)
{   
    //find pivot index
    int pivotIndex = findDuplicatePivotIndex(arr);
    if(pivotIndex==-1)
        return binarySearch(arr, 0, arr.size()-1, target);
    
    if(arr[pivotIndex]==target) return pivotIndex;

    if(target >= arr[0] && target <= arr[pivotIndex]) return binarySearch(arr, 0, pivotIndex, target);
    return binarySearch(arr, pivotIndex+1, arr.size()-1, target);
}

int main()
{
    int n, target, temp;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>target;
    cout<<search(arr, target)<<endl;
}