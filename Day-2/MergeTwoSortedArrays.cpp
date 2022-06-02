#include <iostream>
#include <vector>
using namespace std;
/*

Problem Statement:

Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. 
Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array. 
You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.
*/

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) 
{
    int np = m+n-1, i=m-1, j=n-1;
    while(i>=0 && j>=0)
    {
        if(arr1[i]>arr2[j])
        {
            arr1[np] = arr1[i];
            i--;
            np--;
        }
        else
        {
            arr1[np] = arr2[j];
            j--;
            np--;
        }
    }
    while(i>=0)
    {
        arr1[np] = arr1[i];
        i--;
        np--;
    }
    while(j>=0)
    {
        arr1[np] = arr2[j];
        j--;
        np--;
    }
    return arr1;
}
int main()
{
    vector<int> arr1, arr2;
    int m, n;
    cin>>m>>n;
    int val;
    for(int i=0; i<(m+n); i++)
    {
        cin>>val;
        arr1.push_back(val);
    }
    for(int i=0; i<n; i++)
    {
        cin>>val;
        arr2.push_back(val);
    }
    arr1 = ninjaAndSortedArrays(arr1, arr2, m, n);
    for(int i=0; i<(m+n); i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
}
