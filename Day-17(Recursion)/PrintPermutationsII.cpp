#include <iostream>
#include <vector>
using namespace std;

void helperFunc(vector<int> &arr, int n, int indx)
{
    //base case
    if(indx >= n)
    {
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    //recursive call and small work
    for(int i=indx; i<n; i++)
    {
        swap(arr[i], arr[indx]);
        helperFunc(arr, n, indx+1);
        swap(arr[i], arr[indx]);
    }

}
void PrintPermutationsII(vector<int> &arr, int n)
{
    helperFunc(arr, n, 0);
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    PrintPermutationsII(arr, n);
}