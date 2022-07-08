#include <iostream>
using namespace std;
//to find the empty cells
bool findEmptyLocations(int matrix[9][9], int &row, int &col)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(matrix[i][j] == 0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

//check for safe
bool isSafe(int matrix[9][9], int row, int col, int num)
{
    //check in row
    for(int i=0; i<9; i++) if(matrix[row][i] == num) return false;

    //check in col
    for(int j=0; j<9; j++) if(matrix[j][col] == num) return false;

    //check in grid
    int start_row = (row/3)*3;
    int start_col = (col/3)*3;
    for(int i=start_row; i<(start_row+3); i++)
        for(int j=start_col; j<(start_col+3); j++) if(matrix[i][j] == num) return false;

    return true;
}

bool isItSudoku(int matrix[9][9])
{
    //find the empty location --> if found, start filling it with numbers from 1 to 9
    //                            if not found, return true, since all the empty boxes are filled
    int row, col;
    //base case
    if(!findEmptyLocations(matrix, row, col))
    {
        return true;
    }

    //recursive call and small work
    for(int i=1; i<=9; i++)
    {
        if(isSafe(matrix, row, col, i))
        {
            matrix[row][col] = i;
            if(isItSudoku(matrix)) return true;
            matrix[row][col] = 0;
        }
    }
    return false;
}


int main()
{
    int matrix[9][9];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>matrix[i][j];
            
    bool ans = isItSudoku(matrix);
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}