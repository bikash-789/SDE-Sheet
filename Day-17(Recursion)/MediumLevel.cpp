#include <iostream>
#include <vector>

using namespace std;

//Problem 1- Print all the subsequences of the given array
void printSubseq(int i, vector<int> &subseq, int n, int arr[])
{
    //base case
    if(i>=n)
    {
        for(auto it : subseq)
        {
            cout<<it<<" ";
        }
        if(!subseq.size()) cout<<"[]";
        cout<<endl;
        return;
    }

    //small work and recursive call
    
    //include first element
    subseq.push_back(arr[i]);
    printSubseq(i+1, subseq, n, arr);
    subseq.pop_back();

    //do not include first element
    printSubseq(i+1, subseq, n, arr);

}
int main()
{
    int arr[3] = {1, 2, 3};
    vector<int> subseq;
    printSubseq(0, subseq, 3, arr);
}