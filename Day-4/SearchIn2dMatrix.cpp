#include <iostream>
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int > > &mat, int m, int n, int target) {
    // Write your code here.
    for(int i=0; i<m; i++)
    {
        if(target==mat[i][0]) return true;
        else if(i!=(m-1) && target > mat[i][0] && target < mat[i+1][0])
        {
            for(int j=0; j<n; j++)
            {
                if(target==mat[i][j])
                {
                    return true;
                }
            }
        }
        else if(i==(m-1) && target > mat[i][0] && target <= mat[i][n-1]) 
        {
            for(int j=0; j<n; j++)
            {
                if(target==mat[i][j])
                {
                    return true;
                }
            }
        }
    }
    return false;

}

int main()
{
    int m, n, target;
    cin>>m>>n>>target;
    vector<vector<int> > mat;
    
    for(int i=0; i<m; i++)
    {
        vector<int> row;
        int val;
        for(int j=0; j<n; j++)
        {
            cin>>val;
            row.push_back(val);
        }
        mat.push_back(row);
    }
    if (findTargetInMatrix(mat, m, n, target)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}