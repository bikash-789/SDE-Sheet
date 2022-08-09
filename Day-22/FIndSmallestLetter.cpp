#include <iostream>
#include <vector>

using namespace std;

char findSmallestLetter(vector<char> &letters, char target)
{
    //Find the smallest letter which is greater than target letter
    int n = letters.size();
    int s=0, e=n-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2; //find the mid element
        if(letters[mid] > target) e=mid-1; //move to left
        else s=mid+1; //move to right
    }
    return letters[s%n];    //return s%n
}



int main()
{
    int n;
    cin>>n;
    vector<char> letters;
    char temp, target;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        letters.push_back(temp);
    }
    cin>>target;
    cout<<findSmallestLetter(letters, target)<<endl;
}