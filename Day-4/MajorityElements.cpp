#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    int count = 1;
    int elem = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i]==elem)
        {
            count++;
        }
        else count--;
        if(count==0)
        {
            elem = arr[i];
            count=1;
        }
        
    }
    count=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==elem)
        {
            count++;
        }
    }
    if(count>(n/2)) return elem;
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<findMajorityElement(arr, n)<<endl;
}