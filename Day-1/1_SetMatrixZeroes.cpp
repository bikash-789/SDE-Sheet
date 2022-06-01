#include <iostream>
#include <vector>

using namespace std;

void setMatrixZeroes(vector<vector<int> > &matrix)
{
    //if you find any element zero in given matrix, set its entire row and col to zero
    bool isFirstColZero = false;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0; i<row; i++)
    {
        if(matrix[i][0]==0) isFirstColZero=true;
        for(int j=1; j<col; j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    //now traverse from bottom to top in right to left manner and if matrix[i][0]==0 || matrix[0][j] == 0 set matrix[i][j]==0
    for(int i=row-1; i>=0; i--)
    {
        for(int j=col-1; j>=1; j--)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    //now check for first col
    if(isFirstColZero)
    {
        for(int i=0; i<row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

//function to print matrix
void printMatrix(vector<vector<int> >&matrix)
{
    int row= matrix.size();
    int col= matrix[0].size();
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

//take matrix input
void takeInput(vector< vector<int> > &matrix)
{
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        vector<int> row;
        int val;
        for(int j=0; j<n; j++)
        {
            cin>>val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
}

int main()
{
    vector<vector <int> >matrix;
    takeInput(matrix);
    setMatrixZeroes(matrix);
    printMatrix(matrix);
}