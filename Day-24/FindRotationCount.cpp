#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // Checking if arr[mid] is pivot element or not
        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid > start && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        if (arr[mid] <= arr[start])
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return -1;
}
int findRotationCount(vector<int> &arr)
{
    return findPivotIndex(arr)+1;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    cout << findRotationCount(arr) << endl;
}