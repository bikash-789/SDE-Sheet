#include <iostream>
#include <vector>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    long long maxSum = -99999;

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            sum=0;
        }
        maxSum=max(sum, maxSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<maxSubarraySum(arr, n)<<endl;
}