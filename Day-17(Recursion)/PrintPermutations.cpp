#include <iostream>
#include <vector>
using namespace std;

void helperFunc(vector<int> &arr, int n, vector<int> &ds, int indx, int map[])
{
    //base case
    if(ds.size()==n)
    {
        for(int i=0; i<ds.size(); i++)
        {
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
    }

    //recursive call and small work
    for(int i=0; i<n; i++)
    {
        if(map[i] == -1)
        {
            ds.push_back(arr[i]);
            map[i] = 1;
            helperFunc(arr, n, ds, 0, map);
            map[i] = -1;
            ds.pop_back();
        }
    }

}
void printPermutation(vector<int> &arr, int n)
{
    vector<int> ds;
    int map[n];
    for(int i=0; i<n; i++)
        map[i] = -1;
    helperFunc(arr, n, ds, 0, map);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n=arr.size();
    printPermutation(arr, n);
}