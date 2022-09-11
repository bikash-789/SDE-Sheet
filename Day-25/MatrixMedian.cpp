#include <iostream>
#include <vector>
using namespace std;

int countSmaller(vector<int> &row, int mid)
{
    int l=0, h=row.size()-1;
    while(l<=h)
    {
        int md = l+(h-l)/2;
        if(row[md] <= mid) l=md+1;
        else h=md-1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int l=0, h=1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while(l<=h)
    {
        int mid = l + (h-l)/2;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            count += countSmaller(matrix[i], mid);
        }
        if(count <= ((m*n)/2)) l = mid+1;
        else h = mid-1;
    }
    return l;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix;
    for(int i=0; i<m; i++)
    {
        vector<int> row;
        int temp;
        for(int j=0; j<n; j++)
        {
            cin>>temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }
    cout<<getMedian(matrix)<<endl;
}