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


//Problem 2- Print all the subsequences whose sum is equal to K of the given array
void printSubseqSum(int arr[], int n, int i, vector<int> &subseq, int K)
{
    //base case
    if(i>=n)
    {
        if(K==0)
        {
            //print the subseq
            for(auto it : subseq)
            {
                cout<<it<<" ";
            }
            if(!subseq.size()) cout<<"[]";
            cout<<endl;
        }
        return;
    }

    //recursive call and small work

    //include
    subseq.push_back(arr[i]);
    printSubseqSum(arr, n, i+1, subseq, K-arr[i]);
    subseq.pop_back();


    //do not include
    printSubseqSum(arr, n, i+1, subseq, K);
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    vector<int> subseq;
    printSubseqSum(arr, 4, 0, subseq, 3);
}