#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//given the permutation of 'n' integers, find the next permutation
vector<int> nextPermutation(vector<int> &perm, int n)
{
    //traverse from right to left and find the elem such that a[i] < a[i+1]
    vector<int> output = perm;
    if(n==1) return output;

    int idx1=-1, idx2=0;
    for(int i=n-2; i>=0; i--)
    {
        if(output[i]<output[i+1])
        {
            idx1=i;
            break;
        }
    }

    if(idx1==-1)
    {
        //reverse the output array
        reverse(output.begin(), output.end());
        return output;
    }
    else
    {
        //find a[i]>a[idx1]
        for(int i=n-1; i>=0; i--)
        {
            if(output[i]>output[idx1])
            {
                idx2 = i;
                break;
            }
        }
    }

    swap(output[idx1], output[idx2]);
    reverse(output.begin()+idx1+1, output.end());
    return output;
}

void print(vector<int> &perm, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<perm[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<int> input;
    int val;
    for(int i=0; i<n; i++)
    {   
        cin>>val;
        input.push_back(val);
    }
    vector<int> output = nextPermutation(input, n);
    print(output, n);
}