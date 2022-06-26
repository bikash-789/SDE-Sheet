#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    
    int nextElem=0;
    for(int i=0; i<n; i++)
    {
        arr[nextElem++] = arr[i];
        while(arr[i]==arr[i+1])
            i++;
    }
    return nextElem;
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<removeDuplicates(arr, n)<<endl;
}