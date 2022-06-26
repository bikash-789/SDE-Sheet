#include <iostream>
using namespace std;

long getTrappedWater(long *arr, int n){
    // Write your code here.
    long rMax=0, lMax=0, res=0, l=0, r=n-1;
    
    while(l<r)
    {
        rMax = max(rMax, arr[r]);
        lMax = max(lMax, arr[l]);
        
        if(lMax < rMax)
        {
            res += lMax - arr[l];
            l++;
        }
        else
        {
            res += rMax - arr[r];
            r--;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    long *arr = new long[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    long water = getTrappedWater(arr, n);
    cout<<water<<endl;
}