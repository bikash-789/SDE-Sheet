#include <iostream>
#include <vector>
using namespace std;


int merge(vector<int> &arr, int start, int mid, int end)
{
    int count = 0;
    if(start>=end) return 0;
    
    //create a temp array
    int *temp = new int[end-start+1];
    int i=start, j=mid+1, k=0;
    for(; i<=mid; i++)
    {
        while(j<=end && arr[i] > 2LL * arr[j])
        {
            j++;
        }
        count += (j - (mid+1));
    }
    i=start;
    j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=end)
    {
        temp[k++] = arr[j++];
    }
    //copying to main array
    for(i=start; i<=end; i++)
    {
        arr[i] = temp[i-start];
    }
    return count;
}
int mergeSort(vector<int> &arr, int start, int end)
{
    if(start>=end)
    {
        return 0;
    }
    
    int mid = (start+end)/2;
    
    int ans = mergeSort(arr, start, mid);
    ans += mergeSort(arr, mid+1, end);
    ans += merge(arr, start, mid, end);
    
    return ans;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here
    return mergeSort(arr, 0, n-1);
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<reversePairs(arr, n)<<endl;
}