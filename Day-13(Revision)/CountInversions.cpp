#include <iostream>
using namespace std;

//Create a function for mergesort algorithm

//function to merge arrays
long long merge(long long *arr, int low, int mid, int high)
{
    static long long ansCount = 0;
    //if left is greater than right: do nothing 
    if(low>=high) return 0;

    //create a temporary array of size (right-left+1)
    long long *temp = new long long[high-low+1];

    //Now take two pointers and compare the ith and jth value of both the array.
    int i=low, j=mid+1, k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            ansCount += mid-i+1;    //mid-i+1: means if 'ith-elem' is greater than 'jth-elem' then it is sure that remaining elements to the right of 'i-th elem' are greater than 'j-th elem' because the array is sorted. 
            temp[k++] = arr[j++];
        }
    }
    while(i<j)
    {
        temp[k++] = arr[i++];
    }

    while(j<=high)
    {
        temp[k++] = arr[j++];
    }

    //copy the elements from temp to original array
    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }

    delete []temp;
    return ansCount;
    
}

long long mergeSortHelper(long long *arr, int low, int high)
{
    if(low>=high) return 0;

    int mid = (low+high)/2;

    mergeSortHelper(arr, low, mid);   //sort left half
    mergeSortHelper(arr, mid+1, high); //sort right half

    int ans = merge(arr, low, mid, high);  //now merge the sorted array
    return ans;
}

long long mergeSort(long long *arr, int low, int high)
{
    return mergeSortHelper(arr, low, high);
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n-1);
}

int main()
{
    int n;
    cin>>n;
    long long *arr = new long long[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout<<getInversions(arr, n)<<endl;
}