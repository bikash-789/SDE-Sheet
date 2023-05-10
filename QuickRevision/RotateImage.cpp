#include <iostream>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    // Find the transpose of the matrix
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=i+1; j<matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each of the row in matrix
    for(int i=0; i<matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int> >& matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n, m, val;
    cin>>m;
    cin>>n;

    vector<vector<int> > matrix;
    for(int i=0; i<m; i++)
    {
        vector<int> rows;
        for(int j=0; j<n; j++)
        {
            cin>>val;
            rows.push_back(val);
        }
        matrix.push_back(rows);
        rows.clear();
    }
    rotate(matrix);
    printMatrix(matrix);
}