#include <iostream>
#include <vector>
using namespace std;

//given 'n' find and return the pascal traingle series value
/*
            1
        1       1
    1       1       1
1       1       1       1

*/
vector<vector<long long int> > printPascal(int n)
{
    vector<vector <long long int> >output;
    vector<long long int> one;
    one.push_back(1);
    output.push_back(one);
    if(n==1) return output;

    for(int i=2; i<=n; i++)
    {
        vector<long long int> row;
        row.push_back(1);
        for(int j=1; j<=i-2; j++)
        {
            row.push_back(output[i-2][j-1]+output[i-2][j]);
        }
        row.push_back(1);
        output.push_back(row);
    }
    return output;
}


//print matrix
void printMatrix(vector<vector<long long int> >&matrix)
{
    int row = matrix.size();
    for(int i=0;i<row; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector <long long int> > matrix = printPascal(n);
    printMatrix(matrix);
}