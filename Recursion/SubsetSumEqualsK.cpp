#include <iostream>
using namespace std;

void findSubsets(vector<int> arr, vector<int> subset, int index, int K)
{
    // base case
    if (index == arr.size())
    {
        // K becomes zero, which means subset sum if equal to K
        if (K == 0)
        {
            // print the subset
            for (int i = 0; i < subset.size(); i++)
            {
                cout << subset[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // include into subset
    subset.push_back(arr[index]);
    findSubsets(arr, subset, index + 1, K - arr[index]);

    // exclude from subset
    subset.pop_back();
    findSubsets(arr, subset, index+1, K);
}

void subsetSumEqualsK(vector<int> arr, int K)
{
    // Given the array of integers, we need to find the subsets whose sum is equal to K
    vector<int> subset;
    findSubsets(arr, subset, 0, K);
}

int main()
{
    int n, val, K;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        cin >> val;
        arr.push_back(val);
    }
    cin >> K;
    subsetSumEqualsK(arr, K);
}