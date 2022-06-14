#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Problem Statement


You are given an unsorted array/list 'ARR' of 'N' integers. Your task is to return the length of the longest consecutive sequence.
The consecutive sequence is in the form ['NUM', 'NUM' + 1, 'NUM' + 2, ..., 'NUM' + L] where 'NUM' is the starting integer of the sequence and 'L' + 1 is the length of the sequence.

Note:
If there are any duplicates in the given array we will count only one of them in the consecutive sequence.
*/

//Naive's approach:

// int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
// {
//     //sort the array
//     sort(arr.begin(), arr.end());

//     int prevElemIndex = 0;
//     int currentMax = 1;
//     int ans = 1;

//     for(int i=1; i<n; i++)
//     {
//         while(arr[prevElemIndex]==arr[i])
//         {
//             i++;
//         }
//         if(arr[i]-arr[prevElemIndex] == 1)
//         {
//             currentMax++;
//             ans = max(currentMax, ans);
//         }
//         else currentMax=1;
//         prevElemIndex = i;
//     }
//     return ans;
// }

//Optimized approach
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_map<int, int> map;

    //pushing elements into hashmap
    for(int i=0; i<n; i++)
    {
        map[arr[i]] = map[arr[i]]+1;
    }

    int ans=1;
    //traversing through the array
    for(int i=0; i<n; i++)
    {
        int elem = arr[i]-1;
        if(map[elem])
        {
            continue;
        }
        int count=0;
        int j=arr[i];
        while(map[j])
        {
            count++;
            j++;
        }
        ans=max(ans, count);
    }
    return ans;
}

int main()
{
    int n, val;
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        input.push_back(val);
    }

    cout<<lengthOfLongestConsecutiveSequence(input, n)<<endl;
}