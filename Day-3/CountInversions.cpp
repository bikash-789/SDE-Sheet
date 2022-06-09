#include <iostream>
using namespace std;

long long merge(long long *arr, int start, int mid, int end)
{
    static long long count = 0;
    long long *sorted_arr = new long long[end-start+1];
    int i = start, j = mid+1, k=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            sorted_arr[k++] = arr[i++];
        }
        else
        {   
            count += mid-i+1;
            sorted_arr[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        sorted_arr[k++] = arr[i++];
    }
    while(j<=end)
    {
        sorted_arr[k++] = arr[j++];
    }
    for(int i=start; i<=end; i++)
    {
        arr[i] = sorted_arr[i-start];
    }
    return count;
}

long long mergeSort(long long* arr, int start, int end)
{
    if(start>=end)
    {
        return 0;
    }

    int mid = (start+end)/2;

    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    //merging
    return merge(arr, start, mid, end);

}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}
int main()
{
    int n;
    cin>>n;
    long long *arr = new long long[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<getInversions(arr, n)<<endl;
}