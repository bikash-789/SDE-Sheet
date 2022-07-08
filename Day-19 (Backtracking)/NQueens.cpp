#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    //check for row safe
    for(int i=0; i<n; i++) if(board[row][i] == 1) return false;

    //check for col safe
    for(int j=0; j<n; j++) if(board[j][col] == 1) return false;

    //check for diagonal safe
    int left=col-1, right=col+1;
    for(int i=row-1; i>=0; i--)
    {
        if((left>=0 && board[i][left] == 1) || (right<n && board[i][right]==1)) return false;
        left--;
        right++;
    }

    return true;
}
void helperFunc(vector<vector<int>> &board, int n, int row, vector<vector<int>> &ans)
{
    //base case
    if(row==n)
    {
        vector<int> smallAns;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                smallAns.push_back(board[i][j]);
            }
        }
        ans.push_back(smallAns);
        return;
    }

    
    //recursive call and small work
    for(int j=0; j<n; j++)
    {
        if(isSafe(board, row, j, n))
        {
            board[row][j] = 1;
            helperFunc(board, n, row+1, ans);
            board[row][j] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board;
    for(int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            row.push_back(0);
        }
        board.push_back(row);
    }
    helperFunc(board, n, 0, ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans = solveNQueens(n);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}