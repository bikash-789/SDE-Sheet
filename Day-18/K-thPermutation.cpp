#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


string KthPermutation(int n, int k)
{
    //calculate factorial of (n-1)
    int fact = 1;
    vector<int> nums;
    for(int i=1; i<n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k = k-1; //since the permutation indexing is zero based
    string ans = "";
    while(true)
    {
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if(!nums.size()) break;
        k = k % fact; 
        fact = fact/nums.size();
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    string ans = KthPermutation(n, k);
    cout<<ans<<endl;
}