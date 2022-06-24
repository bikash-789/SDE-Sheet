#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> output;
    
    //sort the array
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        //check for duplicates
        if(i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        
        //two pointers approach
        int l=i+1, h=n-1, tSum = K-arr[i];
        while(l<h)
        {
            if(arr[l] + arr[h] < tSum) l++;
            else if(arr[l] + arr[h] > tSum) h--;
            else
            {
                vector<int> res = {arr[i], arr[l], arr[h]};
                output.push_back(res);
                
                while(l<h && arr[l]==arr[l+1]) l++;
                while(l<h && arr[h-1]==arr[h]) h--;
                
                l++;
                h--;
            }
        }
    }
    return output;
}

int main()
{
    int n, val, K;
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }
    cin>>K;

    vector<vector<int> > output = findTriplets(input, n, K);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i][0]<<" "<<output[i][1]<<" "<<output[i][2]<<endl;
    }

}