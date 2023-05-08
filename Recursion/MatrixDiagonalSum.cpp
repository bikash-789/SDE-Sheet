#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int> > &mat, int leftIndex, int rightIndex, int row)
{
    // base case
    if (row < mat.size())
    {
        int ans = diagonalSum(mat, leftIndex + 1, rightIndex - 1, row + 1);

        if (leftIndex == rightIndex)
        {
            ans += mat[row][leftIndex];
        }
        else
            ans += mat[row][leftIndex] + mat[row][rightIndex];
        return ans;
    }

    return 0;
}
int diagonalSum(vector<vector<int> > &mat)
{
    // Given a square matrix, return the sum of the matrix diagonals
    return diagonalSum(mat, 0, mat.size() - 1, 0);
}

int main()
{
    vector<vector<int> > mat;
    vector<int> rows;
    int n, val;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>val;
            rows.push_back(val);
        }
        mat.push_back(rows);
        rows.clear();
    }
    cout<<diagonalSum(mat)<<endl;
}