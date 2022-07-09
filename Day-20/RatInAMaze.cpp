#include <iostream>
#include <vector>

using namespace std;

void helperFunc(vector<vector<int>> &maze, int n, vector<vector<int>> &paths, vector<vector<int>> &path, int i, int j)
{
    //base case
    if(i==n-1 && j==n-1)
    {
        path[i][j]=1;
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp.push_back(path[i][j]);
            }
        }
        paths.push_back(temp);
        path[i][j]=0;
        return;
    }
    
    if(i>=n || i<0 || j>=n || j<0 || maze[i][j] == 0 || path[i][j] == 1)
    {
        return;
    }
    
    
    
    //recursive call and small work
    path[i][j] = 1;
    helperFunc(maze, n, paths, path, i-1, j);
    helperFunc(maze, n, paths, path, i+1, j);
    helperFunc(maze, n, paths, path, i, j-1);
    helperFunc(maze, n, paths, path, i, j+1);
    path[i][j] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> paths;
    vector<vector<int>> path;
    for(int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            row.push_back(0);
        }
        path.push_back(row);
    }
        
    helperFunc(maze, n, paths, path, 0, 0);
    return paths;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> maze;
    for(int i=0; i<n; i++)
    {
        vector<int> row;
        int val;
        for(int j=0; j<n; j++)
        {
            cin>>val;
            row.push_back(val);
        }
        maze.push_back(row);
    }
    vector<vector<int>> paths = ratInAMaze(maze, n);

    //print the paths
    for(int i=0; i<paths.size(); i++)
    {
        for(int j=0; j<paths[i].size(); j++)
        {
            cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }
}